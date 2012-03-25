/*
 * spy_gpio.h
 *
 * Created: 24.3.2012 17:47:51
 *  Author: savpek
 */ 


#ifndef SPY_GPIO_H_
#define SPY_GPIO_H_

extern void spy_gpio_set_high( uint8_t pin_number);
void (*backup_gpio_set_high)( uint8_t pin_number) = NULL;

extern void spy_gpio_set_low( uint8_t pin_number);
void (*backup_gpio_set_low)( uint8_t pin_number) = NULL;

extern errorc_t spy_gpio_get_input( uint8_t pin_number);
errorc_t (*backup_gpio_get_input)( uint8_t pin_number) = NULL;

extern errorc_t spy_get_last_command( void);
extern void spy_set_input_value( errorc_t new_value);

#endif /* SPY_GPIO_H_ */