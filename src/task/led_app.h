/**
 * @file led_app.h
 * @author Federico Roux (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LED_APP_H
#define __LED_APP_H

#include <led_dt_defines.h>
#include <led.h>

class led_app {


public:

    led_app(){}
    ~led_app(){}
    
    enum class leds_t {LED_GREEN, LED_BLUE, LED_RED};

    int init();
    int fsm();

private:
    leds_t state;
    led l_green;
	led l_blue;
	led l_red;
};

#endif //__LED_APP_H