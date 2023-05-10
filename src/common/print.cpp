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
#include "print.h"

int print_error(std::string msg) {
	printk(ANSI_COLOR_RED "ERROR: "  ANSI_COLOR_RESET "%s\n", msg.c_str());
	return 0;
}

int print_info(std::string msg) {
	printk(ANSI_COLOR_GREEN "INFO: "  ANSI_COLOR_RESET "%s\n", msg.c_str());
	return 0;
}