#ifndef __LED_H
#define __LED_H

#include <zephyr/drivers/gpio.h>


class led {

public:

    int led() {}
    int ~led() {}

    int init(gpio_dt_spec&l) {
        if (!gpio_is_ready_dt(l)) {
		    return 1;
	    }
        if (gpio_pin_configure_dt(l, GPIO_OUTPUT_ACTIVE) < 0) {
		    return 2;
	    }    
        return 0;
    }

    int on() {
        if (gpio_pin_set_dt(&led_green, 1)) {
		    return 1;
	    } 
        return 0;
    }


private:


};

#endif // __LED_H