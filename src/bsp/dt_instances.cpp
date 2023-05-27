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

struct gpio_dt_spec l0_struct = GPIO_DT_SPEC_GET(DT_ALIAS(l0), gpios);
struct gpio_dt_spec l1_struct = GPIO_DT_SPEC_GET(DT_ALIAS(l1), gpios);
struct gpio_dt_spec l2_struct = GPIO_DT_SPEC_GET(DT_ALIAS(l2), gpios);