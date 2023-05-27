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

#include "led_app.h"
#include <led.h>
#include <assert.h>

int led_app::init() {
    /*
    * A build error on this line means your board is unsupported.
    * See the sample documentation for information on how to fix this.
    */

    // if(l_green.init(&led_green)) {
    //     print_error("Failed to initialize green led");
    //     assert(1);
    // }
    
    // if(l_blue.init(&led_blue)) {
    //     print_error("Failed to initialize blue led");
    //     assert(1);
    // }
    // if(l_red.init(&led_red)) {
    //     print_error("Failed to initialize red led");
    //     assert(1);
    // }

    state = leds_t::LED_GREEN;
	print_info("Starting led demo\n");

	print_info("All leds initialized correctly");
    return 0;
}


int led_app::fsm() {

    switch(state) {

        case leds_t::LED_GREEN: {
                printk(ANSI_COLOR_GREEN "Green led" ANSI_COLOR_RESET "\n");
                l_green.on();
                l_blue.off();
                l_red.off();
                state = leds_t::LED_BLUE;
            }
            break;
        case leds_t::LED_BLUE: {
                printk(ANSI_COLOR_BLUE "Blue led" ANSI_COLOR_RESET "\n");
                l_green.off();
                l_blue.on();
                l_red.off();               
                state = leds_t::LED_RED;
            }
            break;
        case leds_t::LED_RED: {
                printk(ANSI_COLOR_RED "Red led" ANSI_COLOR_RESET "\n");
                l_green.off();
                l_blue.off();
                l_red.on();
                state = leds_t::LED_GREEN;
                }
            break;
        default: {
            state = leds_t::LED_GREEN;
            return 1;
        }
    }
    return 0;
}