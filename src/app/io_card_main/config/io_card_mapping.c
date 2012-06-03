#include "framework.h"
#include "io_card_main/config/io_card_mapping.h"

jogwheel_map_t io_input_maps[] = {
		{
			.terminal_name = "5.T0",
			.pin_number = PIN_5T0
		},
		{
			.terminal_name = "5.T1",
			.pin_number = PIN_5T1
		},
		{
			.terminal_name = "5.T2",
			.pin_number = PIN_5T2
		},
        {
            .terminal_name = "5.T3",
            .pin_number = PIN_5T3,
        },        
        {
            .terminal_name = "5.T4",
            .pin_number = PIN_5T4,
        },        
        {
            .terminal_name = "5.T5",
            .pin_number = PIN_5T5,
        },
        {
            .terminal_name = NULL,
            .pin_number = NULL,
        },
	};
    
jogwheel_map_t io_output_maps[] = 
{
        {
            .terminal_name = "2.T0",
            .pin_number = PIN_2T0,
        },
        {
            .terminal_name = "2.T1",
            .pin_number = PIN_2T1,
        },
        {
            .terminal_name = "2.T2",
            .pin_number = PIN_2T2,
        },
        {
            .terminal_name = "2.T3",
            .pin_number = PIN_2T3,
        },
        {
            .terminal_name = NULL,
            .pin_number = NULL,
        },
    };
        
jogwheel_map_t io_adc_maps[] =
{
        {
            .terminal_name = NULL,
            .pin_number = NULL,
        },
};
    