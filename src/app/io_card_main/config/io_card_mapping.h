#ifndef JOGWHEEL_TERMINAL_MAPPING_H_
#define JOGWHEEL_TERMINAL_MAPPING_H_

typedef struct {
	const char* terminal_name;
	const uint8_t pin_number;
} jogwheel_map_t;

extern jogwheel_map_t io_input_maps[];

extern jogwheel_map_t io_output_maps[];

extern jogwheel_map_t io_adc_maps[];

#endif /* JOGWHEEL_TERMINAL_MAPPING_H_ */