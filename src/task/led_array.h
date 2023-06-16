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
#include <string>
#include <led.h>

class led_blink: public led {
public:
    led_blink(led l, uint16_t delay, uint16_t period, std::string name): led(std::move(l)), _delay(delay), _period(period), _name(name) {}

    uint16_t get_delay() { return _delay;}
    uint16_t get_period() { return _period;}
    const char* get_name_c_str() { return _name.c_str();}


private:
    uint16_t _delay;
    uint16_t _period;
    std::string _name;
};

class led_array {
public:

    typedef std::vector<led_blink> led_vector;

    led_array(led_vector lv): _la(std::move(lv)) {}
    ~led_array(){}
    
    int init();

private:
    led_vector _la;
};

#endif //__led_array_H