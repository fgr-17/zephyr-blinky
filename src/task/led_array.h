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

    typedef std::vector<led> led_vector;

    led_array(led_vector lv): _la(std::move(lv)) {}
    ~led_array(){}
    
    int init();

private:
    led_vector _la;
};

#endif //__led_array_H