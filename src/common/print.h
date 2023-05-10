/**
 * @file print.cpp
 * @author Federico Roux (federico.roux@tuta.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRINT_H
#define __PRINT_H

#include <zephyr/sys/printk.h>
#include <ansi_colors.h>
#include <string>

int print_error(std::string msg) {
	printk(ANSI_COLOR_RED "ERROR: "  ANSI_COLOR_RESET "%s\n", msg.c_str());
	return 0;
}

int print_info(std::string msg) {
	printk(ANSI_COLOR_GREEN "INFO: "  ANSI_COLOR_RESET "%s\n", msg.c_str());
	return 0;
}


#endif // __PRINT_H