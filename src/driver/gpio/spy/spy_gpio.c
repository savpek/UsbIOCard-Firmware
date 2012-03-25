/*
 * spy_gpio.c
 *
 * Created: 24.3.2012 17:47:42
 *  Author: savpek
 */ 

#include "framework.h"

errorc_t last_cmd = EC_LOW;
uint8_t last_pin = 0;

errorc_t current_input = EC_LOW;

void spy_gpio_set_high( uint8_t pin_number ) {
	last_pin = pin_number;
	last_cmd = EC_HIGH;
}

void spy_gpio_set_low( uint8_t pin_number ) {
	last_pin = pin_number;
	last_cmd = EC_LOW;
}

errorc_t spy_gpio_get_input( uint8_t pin_number ) {
	return current_input;
}

errorc_t spy_get_last_command( ) {
	return last_cmd;
}

uint8_t spy_get_last_pin( ) {
	return last_pin;
}

void spy_set_input_value( errorc_t new_value ) {
	current_input = new_value;
}
