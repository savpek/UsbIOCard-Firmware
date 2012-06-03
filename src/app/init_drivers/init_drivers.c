#include "framework.h"

#include "app/init_drivers/config/driver_config_usart.h"

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
}