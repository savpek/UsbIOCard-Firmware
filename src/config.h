/*
 * config.h
 *
 * Created: 25.3.2012 15:19:13
 *  Author: savpek
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

/* IO PIN MAPPINGS */


/* UTEST CONFIG */
#include "usart/public/usart.h"
#define UTEST_OUTPUT_CHAR(a) usart_send_char(a)

#endif /* CONFIG_H_ */