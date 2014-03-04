#include "./init_drivers/public/init_drivers.h"

#include "framework.h"
#include "gpio/public/gpio.h"
#include "app/io_card_main/public/io_card_main.h"

void utest_group() 
{
//	RUN_TEST_GROUP(str);
//	RUN_TEST_GROUP(gpio_io_functions);
//	RUN_TEST_GROUP(gpio_adc);
//	RUN_TEST_GROUP(ioapi);
//	RUN_TEST_GROUP(utest);
//	RUN_TEST_GROUP(print);
//	RUN_TEST_GROUP(read);
}

int main(void) {
	#if WDENABLED
		wdt_enable(WDTO_8S);
	#endif
	
	//init_drivers();
	//utest_main(&utest_group);
	
	init_drivers(); // Return to original state after tests.
			        //Driver tests may change these settings.

    io_card_main_thread();
}