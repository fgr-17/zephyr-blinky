/**
 * @file print.h
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

int print_error(std::string msg);
int print_info(std::string msg);
int print_debug(std::string msg);

#endif // __PRINT_H