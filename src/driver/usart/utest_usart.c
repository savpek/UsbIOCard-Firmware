/*! 
 *	@file D:\Dropbox\AVR32\USB_IO_CARD\USB_IO_CARD\src\driver\usart\utest_usart.c
 *  @author: savpek
 *
 *	@brief Test file for unity.
 */ 

#include "framework.h"

/*! @brief Set-up test group for: str
 *	@param Group name */
TEST_GROUP(usart);

/*! @brief Group setup function..
 *	@param Group name */
TEST_SETUP(usart) {

}

/*! @brief Group teardown function..
 *	@param Group name */
TEST_TEAR_DOWN(usart) {

}

/*! @brief TEMPLATE.
 *	@param Group name
 *	@param Test name */
TEST(usart, test_t) {

}

/*	@brief Set up all runnable tests from this module. 
 *	@param group name.*/
TEST_GROUP_RUNNER(usart) {
	RUN_TEST_CASE(usart, test_t);
}