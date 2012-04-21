/*
 * gpio.c
 *
 * Created: 22.3.2012 20:45:43
 *  Author: savpek
 */


#include "framework.h"
#include "gpio/public/gpio.h"

static get_pin_mask(uint8_t pin_number) {
	return (1<<(pin_number%8));
}

/* Addresses are located as following sequence:
	PINA	IO_OFFSET + 0x00
	DDRA	IO_OFFSET + 0x01
	PORTA	IO_OFFSET + 0x02
	PINB	IO_OFFSET + 0x03
	DDRB ... */
static uint8_t get_pin_addr(uint8_t pin_number) {
	/* If pin is 10, divide it by 8 gives
	   1, x3 it and you have 0x03 as address. */
	return (pin_number/8)*3;
}
static uint8_t get_ddrx_addr(uint8_t pin_number) {
	return (pin_number/8)*3+1;
}
static uint8_t get_port_addr(uint8_t pin_number) {
	return (pin_number/8)*3+2;
}

static uint8_t is_pin_set(pin_number) {
	return ((_SFR_IO8 (get_pin_addr(pin_number)&get_pin_mask(pin_number))) == 0);
}

static void set_ddr_bit_low(uint8_t pin_number) {
	_SFR_IO8 (get_ddrx_addr(pin_number)) &= ~get_pin_mask(pin_number);
}

static void set_ddr_bit_high( uint8_t pin_number) {
	_SFR_IO8 (get_ddrx_addr(pin_number)) |= get_pin_mask(pin_number);
}

static void set_port_bit_high( uint8_t pin_number) {
	_SFR_IO8 (get_port_addr(pin_number)) |= get_pin_mask(pin_number);
}

static void set_port_bit_low( uint8_t pin_number) {
	_SFR_IO8 (get_port_addr(pin_number)) &= ~(get_pin_mask(pin_number));
}

/* __SFR_IO8 macro creates pointer and adds offset
 * to address so that it points to correct IO register. */
void gpio_set_high_body( uint8_t pin_number) {
	set_port_bit_high( pin_number);
}
void (*gpio_set_high)( uint8_t pin_number) = &gpio_set_high_body;

void gpio_set_low_body( uint8_t pin_number) {
	set_port_bit_low( pin_number);
}
void (*gpio_set_low)( uint8_t pin_number) = &gpio_set_low_body;

void gpio_init_pin(uint8_t pin_number, gpio_t direction, gpio_t value) {
	if(direction == GPIO_OUTPUT) {
		set_ddr_bit_high( pin_number);
	}
	else {
		set_ddr_bit_low( pin_number);
	}

	if(value == GPIO_HIGH ||
	   value == GPIO_PULL_UP) {
		set_port_bit_high( pin_number);
	   }
	else {
		set_port_bit_low( pin_number);
	}
}

statusc_t gpio_get_input_body( uint8_t pin_number ) {
	if( is_pin_set(pin_number)) {
		return SC_HIGH;
	}
	else {
		return SC_LOW;
	}
}
statusc_t (*gpio_get_input)( uint8_t pin_number) = &gpio_get_input_body;

static uint16_t pin_used_as_adc_flags = 0;
void gpio_init_pin_as_adc( uint8_t pin_number)
{
	ASSERT( ( pin_number <= ADC_LAST_PIN &&
			  pin_number >= ADC_FIRST_PIN ) );

	ADCSRA = ADC_PRESCALE;
	ADMUX = ADC_REF_SOURCE;
	ADMUX |= (1<<ADLAR);	// Left align result registers.
	ADCSRA |= (1<<ADEN);	// Enable.
	ADCSRA |= (1<<ADSC);	// Start conversion.
	
	gpio_init_pin(pin_number, GPIO_INPUT, NULL);
	
	uint8_t current_adc = pin_number - ADC_FIRST_PIN;
	
	ASSERT( ( current_adc >= 0 &&
			  current_adc <= ADC_LAST_PIN-ADC_FIRST_PIN ) );
			  
	pin_used_as_adc_flags |= (1<<current_adc);
}

statusc_t gpio_is_pin_adc( uint8_t pin_number)
{
	uint16_t pin_mask = 1<<(pin_number-ADC_FIRST_PIN);
	if((pin_used_as_adc_flags & pin_mask) != 0)
		return SC_TRUE;
	return SC_FALSE;
}

uint8_t get_adc_value( uint8_t pin_number )
{
	return ADCH;
}
