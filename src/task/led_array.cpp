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

#define STACKSIZE 1024
#define PRIORITY 7

K_THREAD_STACK_DEFINE(my_stack_area, STACKSIZE);
struct k_thread my_thread_data;


void blink(void*void_led, void* void_delay, void* void_period) {

    auto l = static_cast<led*> (void_led);
    auto delay_ms = static_cast<int*> (void_delay);
    auto period_ms = static_cast<int*> (void_period);

    k_msleep(*delay_ms);

    while(1) {
        l->toggle();
        k_msleep(*period_ms);
    }
    return;
}


int led_array::init() {

    print_info("Initializing led array");

    for(auto l:_la) {
        if(l.init()) print_error("Failed to initialize led");
    }

    state = 0;
	print_info("All leds initialized correctly");
    return 0;
}


int led_array::fsm() {

    uint8_t c = 0;
    for(auto&l:_la) {
        if(state == c) {
            l.on();
        }
        else {
            l.off();
        }
        c++;
    }

    if(++state >= _la.size())
        state = 0;

    return 0;
}