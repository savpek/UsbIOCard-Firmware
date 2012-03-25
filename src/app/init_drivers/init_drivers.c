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
	
	gpio_init_pin(PIN_2T0, GPIO_OUTPUT, GPIO_LOW);
	gpio_init_pin(PIN_2T1, GPIO_OUTPUT, GPIO_LOW);
	gpio_init_pin(PIN_2T2, GPIO_OUTPUT, GPIO_LOW);
}