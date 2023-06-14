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