/**
 * @file led.cpp
 * @author fgr-17 (federico.roux@tuta.io)
 * @brief 
 * @version 0.1
 * @date 2023-06-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <led.h>

int led::init() {
    print_debug("led: init without param");
    if(!gpio_is_ready_dt(_l)) return 1;
    if(gpio_pin_configure_dt(_l, GPIO_OUTPUT_ACTIVE) < 0) return 2;
    if(off()) return 3;
    return 0;
}

int led::init(const gpio_dt_spec*l) {
    print_info("led: init with param");
    _l = l;
    return init();
}

int led::on() {
    if (gpio_pin_set_dt(_l, 1)) {
        return 1;
    } 
    _state = state_t::ON;
    return 0;
}

int led::off() {
    if (gpio_pin_set_dt(_l, 0)) {
        return 1;
    } 
    _state = state_t::OFF;
    return 0;
}

int led::toggle() {
    switch (_state) {
    case state_t::ON:
        return(off());

    case state_t::OFF:
        return(on());
    
    default:
        init();
        return 1;
    }
}

const gpio_dt_spec* led::get_dt_spec() const {
    return _l;
}
