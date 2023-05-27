/**
 * @file bsp_instances.cpp
 * @author fgr-17 (federico.roux@tuta.io)
 * @brief 
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <print.h>

#include <led.h>
#include <dt_instances.h>

led led_green{&l0_struct};
led led_blue{&l1_struct};
led led_red{&l2_struct};