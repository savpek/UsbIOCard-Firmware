#ifndef USART_H_
#define USART_H_
#include "framework.h"

extern void usart_init( uint16_t baudrate );
extern statusc_t (*usart_try_read_char)( char* a);
extern void (*usart_send_char)(char a);
#endif /* USART_H_ */