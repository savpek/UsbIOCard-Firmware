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

}

/*! @brief Group teardown function..
 *	@param Group name */
TEST_TEAR_DOWN(gpio) {

}

/*! @brief TEMPLATE.
 *	@param Group name
 *	@param Test name */
TEST(gpio, init) {
	gpio_init_pin(SAFE_PIN, GPIO_OUTPUT, GPIO_OUTPUT);
	
	// Check DDRX register. Should be high.
	TEST_ASSERT(is_bit_set(SAFE_PIN_DDR, SAFE_PIN_IDX));
	TEST_ASSERT(0);
	TEST_ASSERT_EQUAL_INT32(-10, 20);
	TEST_ASSERT_EQUAL_STRING("Joojoo", "jooaaapaajooo");
}

/*	@brief Set up all runnable tests from this module. 
 *	@param group name.*/
TEST_GROUP_RUNNER(gpio) {
	RUN_TEST_CASE(gpio, init);
}