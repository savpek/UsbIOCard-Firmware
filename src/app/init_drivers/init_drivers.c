/*
 * init_drivers.c
 *
 * Created: 21.3.2012 19:34:24
 *  Author: savpek
 */

#include "./usart/public/usart.h"
#include "./gpio/public/gpio.h"

#include "./init_drivers/config/driver_config_usart.h"
#include "init_drivers/config/driver_config_gpio.h"

void init_drivers( ) {
	usart_init(USART_SET_THIS_BAUDRATE);
	
    // HIGH-V RELAY DRIVES
	gpio_init_pin(PIN_2T0, GPIO_OUTPUT, GPIO_LOW);
	gpio_init_pin(PIN_2T1, GPIO_OUTPUT, GPIO_LOW);
	gpio_init_pin(PIN_2T2, GPIO_OUTPUT, GPIO_LOW);
	gpio_init_pin(PIN_2T3, GPIO_OUTPUT, GPIO_LOW);
    
    // INPUTS WITH GALVANIC ISOLATION
	gpio_init_pin(PIN_5T0, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T1, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T2, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T3, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T4, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T5, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T6, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T7, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T8, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T9, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T10, GPIO_INPUT, GPIO_PULL_UP);
	gpio_init_pin(PIN_5T11, GPIO_INPUT, GPIO_PULL_UP);
}