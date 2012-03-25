
#include "./usart/public/usart.h"

#include "framework.h"

static void set_baudrate( uint16_t baudrate) {
	UBRR0H = (baudrate>>8);
	UBRR0L = baudrate;
}

inline static void enable_tx_and_rx() {
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
}

void usart_init( uint16_t baudrate)
{
	set_baudrate( baudrate);
	enable_tx_and_rx();
}

void usart_send_char_body(char a) {
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = a;
}
void (*usart_send_char)(char a) = &usart_send_char_body;