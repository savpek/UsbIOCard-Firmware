/* Common libraries */
#include <avr/io.h>
#include <avr/wdt.h>
#include "config/io_config.h"
#include "config/app_ini.h"

/* Shared status codes and asserts. */
#include "statusc/public/statusc.h"

/* Unit testing framework. */
#include "utest/public/utest.h"

/* Basic output stream */
#include "usart/public/usart.h"

/* Common string paring */
#include "str/public/str.h"

/* SETTINGS ETC... */
#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

/* UTEST default output stream. */
#define UTEST_OUTPUT_CHAR(a) usart_send_char(a)

/* STATUSC default output stream. */
#define STATUSC_ASSERT_OUTPUT_CHAR(a) usart_send_char(a)

/* Common defines. */
#define NULL 0

/* This makes string to be saved in program memory. 
 * Then it doesn't take ram. However, works only with optimization. */
#define PSTR(s) ((const __ATTR_PROGMEM__ char *)(s))

/* Print/Read */
#define PRINT_CHAR_STREAMF(a) usart_send_char(a)
/* IO */

/* Global config files */

/* GPIO Access */
#include "gpio/public/gpio.h"

#endif /* FRAMEWORK_H_ */