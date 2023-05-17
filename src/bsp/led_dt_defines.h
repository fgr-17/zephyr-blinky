/** 
 * @file: led_dt_defines.h
 * 
 * @brief: definitions of devicetree based pins to handle on C/C++ code
 * 
 * @author: federico.roux@tuta.io
 * 
*/

#ifndef __LED_DT_DEFINES
#define __LED_DT_DEFINES

/* Get node directly without aliases */
// #define LED1_NODE DT_NODELABEL(green_led_1)
// #define LED2_NODE DT_NODELABEL(blue_led_0)
// #define LED3_NODE DT_NODELABEL(red_led_1)

#define LED1_NODE DT_ALIAS(l0)
#define LED2_NODE DT_ALIAS(l1)
#define LED3_NODE DT_ALIAS(l2)



#endif // __LED_DT_DEFINES