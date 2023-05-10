/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/kernel.h>
#include <led_app.h>
#include <print.h>

#include "version_git_hash.h"

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS  500


int main(void)
{

	led_app led_set1;

	printk("============================================\n");
	print_info("Version Git Hash:" BLINKY_GIT_HASH);
	printk("============================================\n");

	led_set1.init();
	while (1) {

		led_set1.fsm();
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
