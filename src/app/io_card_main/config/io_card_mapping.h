/*
 * jogwheel_terminal_mapping.h
 *
 * Created: 21.4.2012 18:25:20
 *  Author: savpek
 */ 


#ifndef JOGWHEEL_TERMINAL_MAPPING_H_
#define JOGWHEEL_TERMINAL_MAPPING_H_

typedef struct {
	const char* terminal_name;
	const uint8_t pin_number;
} jogwheel_map_t;

extern jogwheel_map_t io_card_mapping[];

#endif /* JOGWHEEL_TERMINAL_MAPPING_H_ */