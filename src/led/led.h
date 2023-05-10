#ifndef __LED_H
#define __LED_H

#include <zephyr/drivers/gpio.h>


class led {

public:

    led(const gpio_dt_spec*l): _l(l) {}
    ~led() {}

    int init() {
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




private:
    const gpio_dt_spec*_l;

};

#endif // __LED_H