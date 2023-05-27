/**
 * @file led_array.h
 * @author Federico Roux (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __led_array_H
#define __led_array_H

#include <led.h>

class led_array {


public:

    // led_array(){}
    led_array(led&lg, led&lb, led&lr) : l_green(lg), l_blue(lb), l_red(lr) {}
    ~led_array(){}
    
    enum class leds_t {LED_GREEN, LED_BLUE, LED_RED};

    int init();
    int fsm();

private:
    leds_t state;
    led&l_green;
	led&l_blue;
	led&l_red;
};

#endif //__led_array_H