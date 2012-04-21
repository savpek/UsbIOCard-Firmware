/*
 * misc_config.h
 *
 * Created: 21.4.2012 20:29:31
 *  Author: savpek
 */ 


#ifndef MISC_CONFIG_H_
#define MISC_CONFIG_H_

/* UTEST */
#include "usart/public/usart.h"
#define UTEST_OUTPUT_CHAR(a) usart_send_char(a)

/* STATUSC */
#define STATUSC_ASSERT_OUTPUT_CHAR(a) usart_send_char(a)
#endif /* MISC_CONFIG_H_ */