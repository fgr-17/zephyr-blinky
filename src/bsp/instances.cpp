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

led led0{&l0_struct};
led led1{&l1_struct};
led led2{&l2_struct};
led led3{&l3_struct};