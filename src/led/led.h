/**
 * @file led.h
 * @author Federico Roux (federico.roux@tuta.io)
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LED_H
#define __LED_H

#include <print.h>
#include <zephyr/drivers/gpio.h>

class led {

public:

    led() {}
    led(const gpio_dt_spec*l): _l(l) {}
    // led(const gpio_dt_spec l): _l(&l) {}
    ~led() {}

    int init() {
        print_debug("led: init without param");
        if (!gpio_is_ready_dt(_l)) return 1;
        if (gpio_pin_configure_dt(_l, GPIO_OUTPUT_ACTIVE) < 0) return 2;
        return 0;
    }

    int init(const gpio_dt_spec*l) {
        print_info("led: init with param");
        _l = l;
        if (!gpio_is_ready_dt(_l)) return 1;
        if (gpio_pin_configure_dt(_l, GPIO_OUTPUT_ACTIVE) < 0) return 2;
        return 0;
    }

    int on() {
        if (gpio_pin_set_dt(_l, 1)) {
		    return 1;
	    } 
        return 0;
    }

    int off() {
        if (gpio_pin_set_dt(_l, 0)) {
		    return 1;
	    } 
        return 0;
    }


private:
    const gpio_dt_spec*_l;

};

#endif // __LED_H