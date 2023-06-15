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
    ~led() {}

    enum class state_t {ON, OFF};

    int init();
    int init(const gpio_dt_spec*l);
    int on();
    int off();
    int toggle();

private:
    const gpio_dt_spec*_l;
    state_t _state;

};

#endif // __LED_H