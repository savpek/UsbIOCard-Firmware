/* CONFIG FILE FOR USB IO CARD REV1 */
#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

#define PA_OFFSET		0
#define PB_OFFSET		8
#define PC_OFFSET		16
#define PD_OFFSET		24

#define PIN_2T0			PB_OFFSET+0
#define PIN_2T1			PB_OFFSET+1
#define PIN_2T2			PB_OFFSET+2

#define ADC_PRESCALE	((1 << ADPS1)|(1 << ADPS0))	// 8
#define ADC_REF_SOURCE	(1 << REFS0)				// AVCC

#define ADC_FIRST_PIN	PC_OFFSET+0
#define ADC_LAST_PIN	PC_OFFSET+8

#endif /* IO_CONFIG_H_ */