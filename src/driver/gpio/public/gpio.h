#ifndef GPIO_H_
#define GPIO_H_

#include "framework.h"

typedef enum {
	GPIO_INPUT = 0,
	GPIO_OUTPUT = 1,
	GPIO_HIGH = 1,
	GPIO_LOW = 0,
	GPIO_PULL_UP = 1,
    GPIO_NO_PULL_UP = 0,
} gpio_t;


/*! @brief 
 *      Set pin to high state.
 *      Pin must be inited correctly as output before use!
 *  @example: 
 *      gpio_set_high(3); // Set pin 3 high. */
extern void (*gpio_set_high)( uint8_t pin_number);


/*! @brief 
 *      Set pin to low state.
 *      Pin must be inited correctly as output before use!
 *  @example: 
 *      gpio_set_high(3); // Set pin 3 low. */
extern void (*gpio_set_low)( uint8_t pin_number);


/*! @brief 
 *      Returns current pin status, SC_LOW, SC_HIGH.
 *      Pin must be inited correctly as input before use!
 *  @example:
 *      gpio_init_pin(3, GPIO_INPUT, GPIO_PULL_UP);
 *      statusc_t status = gpio_get_input(3); */
extern statusc_t (*gpio_get_input)( uint8_t pin_number);


/*! @brief 
 *      Returns current pin status, SC_LOW, SC_HIGH.
 *      Pin must be inited correctly as input before use!
 *  @example:
 *      gpio
 *      gpio_set_high(3); // Set pin 3 high. */
extern void gpio_init_pin(uint8_t pin_number, gpio_t direction, gpio_t value);

extern void gpio_init_pin_as_adc( uint8_t pin_number);

extern statusc_t gpio_is_pin_adc( uint8_t pin_number);

extern uint8_t gpio_get_adc_value( uint8_t pin_number );

extern statusc_t gpio_is_it_output( uint8_t pin_number);

#endif /* GPIO_H_ */