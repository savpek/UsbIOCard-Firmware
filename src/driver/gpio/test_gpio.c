/*!
 *	@file D:\Dropbox\AVR32\USB_IO_CARD\src\driver\gpio\test_gpio.c
 *  @author: savpek
 *
 *	@brief Test file for unity.
 */

#include "utest/public/utest.h"
#include "framework.h"
#include "gpio/public/gpio.h"

// Don't use pin which may cause damage if it is randomly used
// as input and output ...
#define SAFE_PIN 10
#define SAFE_PIN_PORT PORTB
#define SAFE_PIN_DDR DDRB
#define SAFE_PIN_PIN PINB
#define SAFE_PIN_IDX 2

static uint8_t is_bit_set(uint8_t bit_mask, uint8_t bit_idx) {
	return ((bit_mask&(1<<bit_idx)) != 0);
}

/*! @brief Set-up test group for: gpio
 *	@param Group name */
TEST_GROUP(gpio);

/*! @brief Group setup function..
 *	@param Group name */
TEST_SETUP(gpio) {
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_LOW);
}

/*! @brief Group teardown function..
 *	@param Group name */
TEST_TEAR_DOWN(gpio) {

}

TEST(gpio, init) {
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_HIGH);

	TEST_ASSERT( is_bit_set(SAFE_PIN_DDR, SAFE_PIN_IDX));
	TEST_ASSERT( is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));

	gpio_init_pin(SAFE_PIN, GPIO_INPUT, NULL);

	TEST_ASSERT( !is_bit_set(SAFE_PIN_DDR, SAFE_PIN_IDX));
	TEST_ASSERT( !is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio, set_high) {
	gpio_set_high(SAFE_PIN);

	TEST_ASSERT(is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio, set_low) {
	gpio_set_low(SAFE_PIN);

	TEST_ASSERT( !is_bit_set(SAFE_PIN_PORT, SAFE_PIN_IDX));
}

TEST(gpio, input) {
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_HIGH);	
	gpio_set_low(SAFE_PIN);
	TEST_ASSERT( gpio_get_input(SAFE_PIN) == SC_LOW);

	gpio_set_high(SAFE_PIN);
	TEST_ASSERT( gpio_get_input(SAFE_PIN) == SC_HIGH);
}

/*	@brief Set up all runnable tests from this module.
 *	@param group name.*/
TEST_GROUP_RUNNER(gpio) {
	RUN_TEST_CASE(gpio, init);
	RUN_TEST_CASE(gpio, set_high);
	RUN_TEST_CASE(gpio, set_low);
	RUN_TEST_CASE(gpio, input);
}