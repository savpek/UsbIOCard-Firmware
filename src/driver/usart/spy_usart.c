/*
 * spy_usart.c
 *
 * Created: 21.3.2012 21:21:53
 *  Author: savpek
 */

#include "framework.h"
#include "./usart/spy/spy_usart.h"

char tx_tracker[TX_SIZE] = {0};
uint8_t tx_idx;

char rx_buffer[RX_SIZE] = {0};
uint8_t rx_idx;

void spy_usart_send_char( char a ) { 
	ERRORH_ASSERT(tx_idx < TX_SIZE);
	
	tx_tracker[tx_idx] = a;
	tx_tracker[tx_idx+1] = 0;
}

void spy_usart_tx_read( char* get_this_string )
{
	get_this_string = tx_tracker;
}
