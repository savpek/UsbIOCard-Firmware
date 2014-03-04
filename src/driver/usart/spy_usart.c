#include "framework.h"
#include "./usart/spy/spy_usart.h"

char output_stream[TX_SIZE] = {0};
uint8_t tx_idx = 0;

char* input_stream = NULL;
uint8_t rx_idx = 0;

void spy_usart_send_char( char a ) {
	ASSERT(tx_idx < TX_SIZE);

	output_stream[tx_idx] = a;
	output_stream[tx_idx+1] = 0;
	tx_idx++;
}

char* spy_usart_get_output_buffer()
{
	return output_stream;
}

void spy_usart_reset_output_buffer()
{
	tx_idx = 0;
	output_stream[0] = 0;
}

statusc_t spy_usart_try_read_char(char* a)
{
	if( input_stream != NULL ||
		rx_idx > 15) // Safe limit.
	{
		*a = input_stream[rx_idx];
		rx_idx++;
		return SC_SUCCESS;
	}
	else
	{
		ASSERT( SC_FAILURE);
	}
	return SC_FAILURE;
}

void spy_usart_put_to_receiver_stream(char* source)
{
	input_stream = source;
	rx_idx = 0;
}