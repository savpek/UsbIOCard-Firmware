/*
 * framework.h
 *
 * Created: 21.3.2012 18:59:32
 *  Author: savpek
 */


#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <avr/io.h>
#include "config/io_config.h"
#include "config/misc_config.h"

/* Unit-test framework settings */
#define UTEST_OUTPUT_CHAR(a) usart_send_char(a)
#define UTEST_VERBOSE 1

#include "./utest/public/utest.h"

/* Define common */
#define NULL 0

/* This makes string to be saved in program memory. 
 * Then it doesn't take ram. However, works only with optimization. */
#define PSTR(s) ((const __ATTR_PROGMEM__ char *)(s))

/* Shared status codes and asserts. */
#include "statusc/public/statusc.h"

/* Print/Read */

/* IO */

/* Global config files */

#endif /* FRAMEWORK_H_ */