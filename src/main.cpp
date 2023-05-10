/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS  500

/* The devicetree node identifier for the "led0" alias. */
// #define LED0_NODE DT_ALIAS(led0)
// #define LED1_NODE DT_ALIAS(led1)


/* Get node directly without aliases */
#define LED1_NODE DT_NODELABEL(green_led_1)
#define LED2_NODE DT_NODELABEL(blue_led_1)
#define LED3_NODE DT_NODELABEL(red_led_1)


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

static const struct gpio_dt_spec led_green = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led_blue = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led_red = GPIO_DT_SPEC_GET(LED3_NODE, gpios);


typedef enum {LED_GREEN, LED_BLUE, LED_RED} leds_t;


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int led_on_only (leds_t l) {
	switch(l) {
		case LED_GREEN: {
				printk(ANSI_COLOR_GREEN "Green led" ANSI_COLOR_RESET "\n");
				if (gpio_pin_set_dt(&led_green, 1)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_blue, 0)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_red, 0)) {
					return 1;
				}
			}
			break;
		case LED_BLUE: {
				printk(ANSI_COLOR_BLUE "Blue led" ANSI_COLOR_RESET "\n");
				if (gpio_pin_set_dt(&led_green, 0)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_blue, 1)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_red, 0)) {
					return 1;
				}
			}
			break;
		case LED_RED: {
				printk(ANSI_COLOR_RED "Red led" ANSI_COLOR_RESET "\n");
				if (gpio_pin_set_dt(&led_green, 0)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_blue, 0)) {
					return 1;
				}
				if (gpio_pin_set_dt(&led_red, 1)) {
					return 1;
				}
			}
			break;
		default: {
			return 2;
		}
	}
	return 0;
}


int main(void)
{
	leds_t led_active = LED_GREEN;

	printk("Starting led demo\n");

	if (!gpio_is_ready_dt(&led_green)) {
		return 0;
	}

	if (!gpio_is_ready_dt(&led_blue)) {
		return 0;
	}

	if (!gpio_is_ready_dt(&led_red)) {
		return 0;
	}

	if (gpio_pin_configure_dt(&led_green, GPIO_OUTPUT_ACTIVE) < 0) {
		return 0;
	}

	if (gpio_pin_configure_dt(&led_blue, GPIO_OUTPUT_ACTIVE) < 0) {
		return 0;
	}

	if (gpio_pin_configure_dt(&led_red, GPIO_OUTPUT_ACTIVE) < 0) {
		return 0;
	}


	if (gpio_pin_set_dt(&led_green, 1)) {
		return 0;
	}

	led_active = LED_BLUE;



	while (1) {


		switch(led_active) {

			case LED_GREEN: {
					led_on_only(LED_GREEN);
					led_active = LED_BLUE;
				}
				break;
			case LED_BLUE: {
					led_on_only(LED_BLUE);
					led_active = LED_RED;
				}
				break;
			case LED_RED: {
					led_on_only(LED_RED);
					led_active = LED_GREEN;
					}
				break;
			default: {
				
				}
				return 0;
		}

		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}