/*
 * spy_gpio.c
 *
 * Created: 24.3.2012 17:47:42
 *  Author: savpek
 */

#include "framework.h"
#include "gpio/public/gpio.h"

statusc_t last_cmd = SC_LOW;
uint8_t last_pin = 0;

statusc_t current_input = SC_LOW;

void spy_gpio_set_high( uint8_t pin_number ) {
	last_pin = pin_number;
	last_cmd = SC_HIGH;
}

void spy_gpio_set_low( uint8_t pin_number ) {
	last_pin = pin_number;
	last_cmd = SC_LOW;
}

statusc_t spy_gpio_get_input( uint8_t pin_number ) {
	return current_input;
}

statusc_t spy_gpio_get_last_command( ) {
	return last_cmd;
}

uint8_t spy_gpio_get_last_pin( ) {
	return last_pin;
}

void spy_gpio_set_input_value( statusc_t new_value ) {
	current_input = new_value;
}