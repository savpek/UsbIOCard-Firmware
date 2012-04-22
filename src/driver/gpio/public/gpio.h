#ifndef GPIO_H_
#define GPIO_H_

#include "framework.h"

typedef enum {
	GPIO_INPUT = 0,
	GPIO_OUTPUT = 1,
	GPIO_HIGH = 1,
	GPIO_LOW = 0,
	GPIO_PULL_UP = 1,
} gpio_t;

extern void (*gpio_set_high)( uint8_t pin_number);

extern void (*gpio_set_low)( uint8_t pin_number);

extern statusc_t (*gpio_get_input)( uint8_t pin_number);

extern void gpio_init_pin(uint8_t pin_number, gpio_t direction, gpio_t value);

extern void gpio_init_pin_as_adc( uint8_t pin_number);

extern statusc_t gpio_is_pin_adc( uint8_t pin_number);

extern uint8_t gpio_get_adc_value( uint8_t pin_number );

extern statusc_t gpio_is_it_output( uint8_t pin_number);

#endif /* GPIO_H_ */