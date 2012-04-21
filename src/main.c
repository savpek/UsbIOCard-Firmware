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
	init_drivers();

//	RUN_TEST_GROUP(str);

	RUN_TEST_GROUP(gpio);
//	RUN_TEST_GROUP(ioapi);
//	RUN_TEST_GROUP(utest);
}

int main(void) {
	utest_main(&utest_wrapper);

	while(1)
    {
	//usart_send_char('a');
    }

}