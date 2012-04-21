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

extern void gpio_init_port_b(uint8_t pin_dir_map, uint8_t value);
extern void gpio_init_port_c(uint8_t pin_dir_map, uint8_t value);

#endif /* GPIO_H_ */