/*
 * spy_usart.h
 *
 * Created: 21.3.2012 21:22:14
 *  Author: savpek
 */ 


#ifndef SPY_USART_H_
#define SPY_USART_H_

/* Tracker buffer sizes. */
#define TX_SIZE 25
#define RX_SIZE 25

extern void spy_usart_send_char( char a);
void (*usart_send_char_backup)( char a);

/*! @brief Get single character from TX buffer.
 *		   Every time you send character with spy_usart_send_char(a),
 *         it is saved to buffer.
 *
 *	@param uint8_t get_this_idx
 *
 * 	@return extern void: */
extern void spy_usart_tx_get( uint8_t get_this_idx);


/*! @brief Return pointer to TX buffer (string).
 *
 *	@param char * get_this_string 
 *
 * 	@return extern void: */
extern void spy_usart_tx_read( char* get_this_string);


/*! @brief Reset TX buffer.
 *
 *	@param void
 *
 * 	@return extern void: */
extern void spy_usart_reset_tx( void);


extern void spy_usart_rx_put( char* this_string);

#endif /* SPY_USART_H_ */