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
#include <stdarg.h>
#include "print.h"


// #define __DEBUG 0

int print_error(const char *format, ...) {
	va_list args;
    va_start(args, format);
	printf(ANSI_COLOR_RED "ERROR: "  ANSI_COLOR_RESET );
	vprintf(format, args);
	printf("\n");
	va_end(args);
	return 0;
}

int print_info(const char *format, ...) {

	va_list args;
    va_start(args, format);
	printf(ANSI_COLOR_GREEN "INFO: "  ANSI_COLOR_RESET );
	vprintf(format, args);
	printf("\n");
	va_end(args);
	return 0;
}

int print_debug(const char *format, ...) {
#ifdef __DEBUG
	va_list args;
    va_start(args, format);
	printf(ANSI_COLOR_YELLOW "DEBUG: "  ANSI_COLOR_RESET );
	vprintf(format, args);
	printf("\n");
	va_end(args);
#endif
	return 0;
}
