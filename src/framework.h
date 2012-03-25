/*
 * framework.h
 *
 * Created: 21.3.2012 18:59:32
 *  Author: savpek
 */


#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <avr/io.h>

/* Unit-test framework settings */
#define UTEST_OUTPUT_CHAR(a) usart_send_char(a)
#define UTEST_VERBOSE 1

#include "./utest/public/utest.h"

/* Define common */
#define NULL 0

/* This makes string to be saved in program memory. 
 * Then it doesn't take ram. However, works only with optimization. */
#define PSTR(s) ((const __ATTR_PROGMEM__ char *)(s))

/* Error handlers */
#include "./errorh/public/errorh.h"

/* Print/Read */

/* IO */

#endif /* FRAMEWORK_H_ */