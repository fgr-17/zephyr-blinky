/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/kernel.h>
#include <led_array.h>
#include <print.h>

#include <instances.h>


#include "version_git_hash.h"
#include "version_git_branch.h"

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS  500


int main(void) {

	led_array led_array(led_green, led_blue, led_red);

	printk("============================================\n");
    print_info("Board: " CONFIG_BOARD);
	print_info("Git Info:" BLINKY_GIT_HASH "@" BLINKY_GIT_BRANCH);
	printk("============================================\n");

	led_array.init();

	while (1) {
		led_array.fsm();
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
