/* CONFIG FILE FOR USB IO CARD REV1 */
#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

#define PA_OFFSET		0
#define PB_OFFSET		8
#define PC_OFFSET		16
#define PD_OFFSET		24

// HIGH-V RELAY DRIVES
#define PIN_2T0			PB_OFFSET+0
#define PIN_2T1			PB_OFFSET+1
#define PIN_2T2			PB_OFFSET+2
#define PIN_2T3			PB_OFFSET+2

// INPUTS WITH CALVANIC ISOLATION
#define PIN_5T0
#define PIN_5T1
#define PIN_5T2
#define PIN_5T3
#define PIN_5T4
#define PIN_5T5
#define PIN_5T6
#define PIN_5T7
#define PIN_5T8
#define PIN_5T9
#define PIN_5T11
#define PIN_5T12

// ADC INPUTS
#define PIN_7T0_ADC0
#define PIN_7T0_ADC1

#define ADC_PRESCALE	((1 << ADPS1)|(1 << ADPS0))	// 8
#define ADC_REF_SOURCE	(1 << REFS0)				// AVCC

#define ADC_FIRST_PIN	PC_OFFSET+0
#define ADC_LAST_PIN	PC_OFFSET+8

#endif /* IO_CONFIG_H_ */