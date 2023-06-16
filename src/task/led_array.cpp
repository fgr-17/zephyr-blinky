/**
 * @file led_fsm.cpp
 * @author fgr17 (federico.roux@tuta.io)
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <print.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include "led_array.h"
#include <led.h>

#include <typeinfo>


/** @brief number of threads */
#define THREADS_N       (4)
/** stack size for each thread */
#define STACKSIZE       (1024)
/** threads priority */
#define PRIORITY        (7)

/** array of stack slices for each thread */
K_THREAD_STACK_ARRAY_DEFINE(my_stack_area, THREADS_N, STACKSIZE);
struct k_thread my_thread_data[THREADS_N];

/** 
 * @function blink
 * 
 * @param void_led led class with led driver inherited + delay and period
*/
void blink(void*void_led, void*, void*) {

    auto l = static_cast<led_blink*> (void_led);

    print_info("Thread started");
    printk("Initial delay: %d\n", l->_delay);
    printk("Period: %d\n", l->_period);
    k_msleep(l->_delay);

    while(1) {
        k_msleep(l->_period);
        l->toggle();
    }
    return;
}

/**
 * @brief init
 * 
 * @return initialize led and starts all threads
 */

int led_array::init() {

    uint8_t i = 0;
    print_info("Initializing led array");

    for(auto&l:_la) {

        if(l.is_led_ready()) {

            if(l.init()) print_error("Failed to initialize led");
            k_tid_t tid = k_thread_create(&my_thread_data[i], my_stack_area[i], STACKSIZE,
                            blink, static_cast<void*>(&l), NULL, NULL,
                            PRIORITY, 0, K_NO_WAIT);

            if(tid == NULL) {
                print_error("Failed to create thread");
            }
            
            k_thread_name_set(&my_thread_data[i], "blink");
            i++;
        }
        else {
            print_error("Led is not ready for the current board");
        }

    }

	print_info("All leds initialized correctly");

    return 0;
}
