#include "framework.h"
const char *command_set = "SET";
const char *command_read = "READ";
const char *error_msg = "ERROR";

#include "gpio/public/gpio.h"

void io_card_main_thread() {

    char read_buffer[10] = {0};

	while(1)
		{
			read_line(read_buffer, 10);


			if(str_compare("AAA", read_buffer, ~0) )
            {
                print_char('1');
                gpio_set_low(PIN_2T0);    
            }
            else
            {
                print_char('2');
                gpio_set_high(PIN_2T0);
            }             
		}
}