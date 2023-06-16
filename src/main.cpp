/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/kernel.h>
#include <led_array.h>
#include <print.h>

#include <vector>

#include <instances.h>

#include "version_git_hash.h"
#include "version_git_branch.h"

#define SLEEP_TIME_MS  500

int main(void) {

	led_array leds(led_array::led_vector {{led0, 0, 1000}, 
										  {led1, 300, 1000},
										  {led2, 600, 1000},
										  {led3, 900, 1000}});

	printk("==================================================\n");
    print_info("Board: " CONFIG_BOARD);
	print_info("Git Info:" BLINKY_GIT_HASH "@" BLINKY_GIT_BRANCH);
	printk("==================================================\n");

	leds.init();

	while (1) {
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
