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

#include <stdint.h>
#include <vector>
#include <led.h>

class led_array {


public:

    // led_array(){}
    typedef std::vector<led> led_vector;

    // led_array(led&lg, led&lb, led&lr) : l_green(lg), l_blue(lb), l_red(lr) {}
    led_array(led_vector lv): _la(std::move(lv)) {}
    ~led_array(){}
    
    // enum class leds_t {LED_GREEN, LED_BLUE, LED_RED};

    int init();
    int fsm();

private:
    uint8_t state;
    // led&l_green;
	// led&l_blue;
	// led&l_red;

    led_vector _la;



};

#endif //__led_array_H