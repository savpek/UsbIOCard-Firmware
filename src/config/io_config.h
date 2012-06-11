/* CONFIG FILE FOR USB IO CARD REV1 */
#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

#define PA_OFFSET		0
#define PB_OFFSET		8
#define PC_OFFSET		16
#define PD_OFFSET		24
#define ADC_OFFSET      16

// HIGH-V RELAY DRIVES
#define PIN_2T0			PB_OFFSET+0
#define PIN_2T1			PB_OFFSET+1
#define PIN_2T2			PB_OFFSET+7
#define PIN_2T3			PB_OFFSET+6

// INPUTS WITH CALVANIC ISOLATION
#define PIN_5T0         PD_OFFSET+2
#define PIN_5T1         PD_OFFSET+3
#define PIN_5T2         PD_OFFSET+4
#define PIN_5T3         PD_OFFSET+5
#define PIN_5T4         PD_OFFSET+6
#define PIN_5T5         PD_OFFSET+7
#define PIN_5T6         PB_OFFSET+2
#define PIN_5T7         PC_OFFSET+0
#define PIN_5T8         PC_OFFSET+1
#define PIN_5T9         PC_OFFSET+2
#define PIN_5T10        PC_OFFSET+3
#define PIN_5T11        PC_OFFSET+4

// ADC INPUTS
// Notice: These ports are only for adc,
// so they doesn't need normal IO pins.
#define PIN_7T0_ADC0   ADC_OFFSET+6
#define PIN_7T0_ADC1   ADC_OFFSET+7

#define ADC_PRESCALE	((1 << ADPS1)|(1 << ADPS0))	// 8
#define ADC_REF_SOURCE	(0)    			            // VREF

// These are not used in current solution since all
// used adcs are in special pins (pins only have ADC functions).
#define ADC_FIRST_PIN	PC_OFFSET+0
#define ADC_LAST_PIN	PC_OFFSET+8

#endif /* IO_CONFIG_H_ */