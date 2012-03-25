/*
 * usart.h
 *
 * Created: 21.3.2012 18:28:58
 *  Author: savpek
 */


#ifndef USART_H_
#define USART_H_

#include "framework.h"

extern void usart_init( uint16_t baudrate );
extern void (*usart_send_char)(char a);

#endif /* USART_H_ */