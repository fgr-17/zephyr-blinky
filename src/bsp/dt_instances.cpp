/**
 * @file dt_instances.cpp
 * @author fgr-17 (federico.roux@tuta.io)
 * @brief 
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

struct gpio_dt_spec l0_struct = GPIO_DT_SPEC_GET_OR(DT_ALIAS(l0), gpios, {0});
struct gpio_dt_spec l1_struct = GPIO_DT_SPEC_GET_OR(DT_ALIAS(l1), gpios, {0});
struct gpio_dt_spec l2_struct = GPIO_DT_SPEC_GET_OR(DT_ALIAS(l2), gpios, {0});
struct gpio_dt_spec l3_struct = GPIO_DT_SPEC_GET_OR(DT_ALIAS(l3), gpios, {0});