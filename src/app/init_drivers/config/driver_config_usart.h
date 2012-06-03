#ifndef DRIVER_CONFIG_USART_H_
#define DRIVER_CONFIG_USART_H_

/* These are defined in datasheet, change if needed. */

/* 8Mhz FMCU, 9600 -> */
#define USART_BAUD_9600 51

/* Actual selection of baudrate. */
#define USART_SET_THIS_BAUDRATE			USART_BAUD_9600

#endif /* DRIVER_CONFIG_USART_H_ */