#ifndef SPY_GPIO_H_
#define SPY_GPIO_H_

extern void spy_gpio_set_high( uint8_t pin_number);

extern void spy_gpio_set_low( uint8_t pin_number);

extern statusc_t spy_gpio_get_input( uint8_t pin_number);

extern statusc_t spy_gpio_get_last_command( void);
extern void spy_gpio_set_input_value( statusc_t new_value);

#endif /* SPY_GPIO_H_ */