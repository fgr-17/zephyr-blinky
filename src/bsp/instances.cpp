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
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


#include <led.h>

led led_green{GPIO_DT_SPEC_GET(DT_ALIAS(l0), gpios)};
led led_blue{GPIO_DT_SPEC_GET(DT_ALIAS(l1), gpios)};
led led_red{GPIO_DT_SPEC_GET(DT_ALIAS(l2), gpios)};