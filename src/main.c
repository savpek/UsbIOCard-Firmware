/*
 * USB_IO_CARD.c
 *
 * Created: 21.3.2012 18:25:48
 *  Author: savpek
 */

#include <avr/io.h>
#include <stdio.h>
#include "./usart/public/usart.h"
#include "./init_drivers/public/init_drivers.h"

#include "framework.h"
#include "gpio/public/gpio.h"

void utest_wrapper() {
	RUN_TEST_GROUP(gpio);
}

int main(void) {
	init_drivers();
	utest_main(&utest_wrapper);
	
	while(1)
    {
//	usart_send_char('a');
    }
	
}