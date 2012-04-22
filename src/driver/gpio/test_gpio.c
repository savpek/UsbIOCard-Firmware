#include "framework.h"
#include "gpio/public/gpio.h"

// Don't use pin which may cause damage if it is randomly used
// as input and output ...
#define SAFE_PIN 10
#define SAFE_PIN_PORT PORTB
#define SAFE_PIN_DDR DDRB
#define SAFE_PIN_PIN PINB
#define SAFE_PIN_IDX 2

/* COMMON IO GROUP */
TEST_GROUP(gpio_io_functions);

TEST_SETUP(gpio_io_functions) {
}

TEST_TEAR_DOWN(gpio_io_functions) {

}

static uint8_t is_bit_set(uint8_t bit_mask, uint8_t bit_idx) {
	return ((bit_mask&(1<<bit_idx)) != 0);
}

TEST(gpio_io_functions, init)
{
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_HIGH);

	TEST_ASSERT( is_bit_set(SAFE_PIN_DDR, SAFE_PIN_IDX));
	TEST_ASSERT( is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));

	gpio_init_pin(SAFE_PIN, GPIO_INPUT, NULL);

	TEST_ASSERT( !is_bit_set(SAFE_PIN_DDR, SAFE_PIN_IDX));
	TEST_ASSERT( !is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio_io_functions, set_high)
{
	gpio_set_high(SAFE_PIN);

	TEST_ASSERT( is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio_io_functions, set_low)
{
	gpio_set_low(SAFE_PIN);

	TEST_ASSERT( !is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio_io_functions, input)
{
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_HIGH);
	gpio_set_low(SAFE_PIN);
	TEST_ASSERT( gpio_get_input(SAFE_PIN) == SC_LOW);

	gpio_set_high(SAFE_PIN);
	TEST_ASSERT( gpio_get_input(SAFE_PIN) == SC_HIGH);
}

TEST(gpio_io_functions, is_it_output)
{
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_HIGH);
	TEST_ASSERT( gpio_is_it_output( SAFE_PIN) == SC_TRUE);
	
	gpio_init_pin(SAFE_PIN, GPIO_INPUT, GPIO_LOW);
	TEST_ASSERT( gpio_is_it_output( SAFE_PIN) == SC_FALSE);
}

TEST_GROUP_RUNNER(gpio_io_functions)
{
	RUN_TEST_CASE(gpio_io_functions, init);
	RUN_TEST_CASE(gpio_io_functions, set_high);
	RUN_TEST_CASE(gpio_io_functions, set_low);
	RUN_TEST_CASE(gpio_io_functions, input);
	RUN_TEST_CASE(gpio_io_functions, is_it_output);
}

/* ADC GROUP */
TEST_GROUP(gpio_adc);

TEST_SETUP(gpio_adc)
{
}

TEST_TEAR_DOWN(gpio_adc)
{

}

#define FIRST_ADC_PIN 16
#define FIRST_ADC_DDR DDRC
#define FIRST_ADC_PIN_NUMBER 0
TEST(gpio_adc, init_adc_registers) {
	gpio_init_pin_as_adc( FIRST_ADC_PIN);

	TEST_ASSERT( (ADC_PRESCALE&ADCSRA) != 0 );	// Is prescaler set correctly.
	TEST_ASSERT( (ADC_REF_SOURCE&ADMUX) != 0);	// Is reference source correct.
	TEST_ASSERT( ((1<<ADLAR)&ADMUX) != 0);		// Left result register for easier reading.
	TEST_ASSERT( ((1<<ADEN)&ADCSRA) != 0);		// Enable.
	TEST_ASSERT( ((1<<ADIF)&ADCSRA) != 0);		// Conversion started.
												// This bit is set with ADSC.
}

TEST(gpio_adc, io_set_correctly_as_input)
{
	FIRST_ADC_DDR |= (1<<FIRST_ADC_PIN_NUMBER); // Set DDRD to 1 to make sure it isn't set.
	gpio_init_pin_as_adc( FIRST_ADC_PIN);

	TEST_ASSERT( !is_bit_set(FIRST_ADC_DDR, FIRST_ADC_PIN_NUMBER));
}

TEST(gpio_adc, adc_used_flags_are_set_and_readed_correctly)
{
	gpio_init_pin_as_adc(FIRST_ADC_PIN);
	TEST_ASSERT( gpio_is_pin_adc(FIRST_ADC_PIN) == SC_TRUE);

	TEST_ASSERT( gpio_is_pin_adc(FIRST_ADC_PIN+1) == SC_FALSE);
	
	gpio_init_pin_as_adc(FIRST_ADC_PIN+1);
	TEST_ASSERT( gpio_is_pin_adc(FIRST_ADC_PIN+1) == SC_TRUE);
}

TEST_GROUP_RUNNER(gpio_adc) {
	RUN_TEST_CASE(gpio_adc, init_adc_registers);
	RUN_TEST_CASE(gpio_adc, io_set_correctly_as_input);
	RUN_TEST_CASE(gpio_adc, adc_used_flags_are_set_and_readed_correctly);
}

/* PWM GROUP */
//TODO: FUNCTIONALITY