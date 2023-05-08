/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS  500

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)


/* Get node directly without aliases */
// #define LED0_NODE DT_NODELABEL(blue_led_1)
// #define LED1_NODE DT_NODELABEL(red_led_1)


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led_blue = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led_red = GPIO_DT_SPEC_GET(LED1_NODE, gpios);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led_blue)) {
		return 0;
	}

	if (!gpio_is_ready_dt(&led_red)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led_blue, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}


	ret = gpio_pin_configure_dt(&led_red, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}


	ret = gpio_pin_toggle_dt(&led_blue);
	if (ret < 0) {
		return 0;
	}

	while (1) {
		ret = gpio_pin_toggle_dt(&led_blue);
		if (ret < 0) {
			return 0;
		}

		ret = gpio_pin_toggle_dt(&led_red);
		if (ret < 0) {
			return 0;
		}

		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
