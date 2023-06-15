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

#define STACKSIZE 1024
#define PRIORITY 7

K_THREAD_STACK_DEFINE(my_stack_area, STACKSIZE);
struct k_thread my_thread_data;


void blink(void*void_led, void* void_delay, void* void_period) {

    auto l = static_cast<led*> (void_led);
    auto delay_ms = static_cast<int*> (void_delay);
    auto period_ms = static_cast<int*> (void_period);

    print_info("Thread started");
    printk("Initial delay: %d\n", *delay_ms);
    printk("Period: %d\n", *period_ms);

    k_msleep(*delay_ms);

    printk("l pointer task %p\n", &l);


    while(1) {
        print_info("Led toggle");
        k_msleep(1000);
        l->toggle();
    }
    return;
}

int d = 1000;
int p = 1000;

int led_array::init() {

    print_info("Initializing led array");

    // for(auto l:_la) {
    //     if(l.init()) print_error("Failed to initialize led");
    //     k_tid_t tid = k_thread_create(&my_thread_data, my_stack_area, STACKSIZE,
    //                     blink, static_cast<void*>(&l), static_cast<void*>(&d), static_cast<void*>(&p),
    //                     PRIORITY, 0, K_NO_WAIT);

    //     printk("l pointer %p\n", &l);
        
    //     if(tid == NULL) {
    //         print_error("Failed to create thread");
    //     }
        
    //     k_thread_name_set(&my_thread_data, "blink 0");
    // }


    printk("l pointer %p\n", &_la[0]);

    if(_la[0].init()) print_error("Failed to initialize led");

    k_tid_t tid = k_thread_create(&my_thread_data, my_stack_area, STACKSIZE,
                                    blink, static_cast<void*>(&_la[0]), static_cast<void*>(&d), static_cast<void*>(&p),
                                    PRIORITY, 0, K_NO_WAIT);


    if(tid == NULL) {
        print_error("Failed to create thread");
    }

	print_info("All leds initialized correctly");

    return 0;
}
