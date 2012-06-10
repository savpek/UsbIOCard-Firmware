#ifndef JOGWHEEL_TERMINAL_MAPPING_H_
#define JOGWHEEL_TERMINAL_MAPPING_H_

typedef struct {
	const char* terminal_name;
	const uint8_t pin_number;
} jogwheel_map_t;

extern jogwheel_map_t io_input_map[];

extern jogwheel_map_t io_output_map[];

extern jogwheel_map_t adc_map[];

#endif /* JOGWHEEL_TERMINAL_MAPPING_H_ */