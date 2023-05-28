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

    // if(l_green.init()) {
    //     print_error("Failed to initialize green led");
    // }
    
    // if(l_blue.init()) {
    //     print_error("Failed to initialize blue led");
    // }
    // if(l_red.init()) {
    //     print_error("Failed to initialize red led");
    // }


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

    // switch(state) {

    //     case leds_t::LED_GREEN: {
    //             printk(ANSI_COLOR_GREEN "Green led" ANSI_COLOR_RESET "\n");
    //             l_green.on();
    //             l_blue.off();
    //             l_red.off();
    //             state = leds_t::LED_BLUE;
    //         }
    //         break;
    //     case leds_t::LED_BLUE: {
    //             printk(ANSI_COLOR_BLUE "Blue led" ANSI_COLOR_RESET "\n");
    //             l_green.off();
    //             l_blue.on();
    //             l_red.off();               
    //             state = leds_t::LED_RED;
    //         }
    //         break;
    //     case leds_t::LED_RED: {
    //             printk(ANSI_COLOR_RED "Red led" ANSI_COLOR_RESET "\n");
    //             l_green.off();
    //             l_blue.off();
    //             l_red.on();
    //             state = leds_t::LED_GREEN;
    //             }
    //         break;
    //     default: {
    //         state = leds_t::LED_GREEN;
    //         return 1;
    //     }
    // }
    return 0;
}