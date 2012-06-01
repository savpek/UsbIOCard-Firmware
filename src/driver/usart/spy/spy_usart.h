#ifndef SPY_USART_H_
#define SPY_USART_H_

/* Tracker buffer sizes. */
#define TX_SIZE 25
#define RX_SIZE 25

extern void spy_usart_send_char( char a);
extern char* spy_usart_get_output_buffer( void);
extern void spy_usart_reset_output_buffer( void);
extern void spy_usart_put_to_tracker( char* put_this);
extern void spy_usart_put_to_receiver_stream(char* source);
extern statusc_t spy_usart_try_read_char(char* a);
#endif /* SPY_USART_H_ */