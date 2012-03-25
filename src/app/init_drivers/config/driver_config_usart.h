/*
 * driver_config_usart.h
 *
 * Created: 21.3.2012 19:35:09
 *  Author: savpek
 */ 


#ifndef DRIVER_CONFIG_USART_H_
#define DRIVER_CONFIG_USART_H_

/* These are defined in datasheet, change if needed. */

/* 8Mhz FMCU, 9600 -> */
#define USART_BAUD_9600 51

/* Actual selection of baudrate. */
#define USART_SET_THIS_BAUDRATE			USART_BAUD_9600

#endif /* DRIVER_CONFIG_USART_H_ */