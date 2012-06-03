#include "framework.h"
#include "app/io_card_main/config/io_card_mapping.h"

const char *error_msg_header = "ERROR: ";

#define LOCATION_COMMAND 0

static void error_invalid_command()
{
    print_line(error_msg_header);
    print_line("Invalid command! Commands available R/S/A.");
}

static void error_invalid_pin()
{
    print_line(error_msg_header);
    print_line("Invalid pin!");
}

static void error_invalid_pin_state()
{
    print_line(error_msg_header);
    print_line("Invalid pin state!");
}

#define PIN_STRING_TOKEN_IDX 1
static jogwheel_map_t try_find_pin_from_list(jogwheel_map_t *list, char* read_buffer)
{
    uint8_t pin_name_begin_idx = 0;
    uint8_t pin_name_end_idx = 0;
    
    if( str_get_token_indexes(  read_buffer, 
                                ' ', 
                                PIN_STRING_TOKEN_IDX, 
                                &pin_name_begin_idx, 
                                &pin_name_end_idx)
        != SC_SUCCESS)
        return;
    
    for(uint8_t i = 0; list[i].terminal_name != NULL; i++)
    {
        if( str_is_substring_of(
                        read_buffer,
                        list[i].terminal_name,
                        pin_name_begin_idx) 
            == SC_TRUE)
            return list[i];
    }

    return;
}

static void try_get_pin_adc( char *read_buffer ) 
{
    //jogwheel_map_t pin = try_find_pin_from_list( io_adc_maps);
}

static void try_read_pin( char *read_buffer ) 
{
    //jogwheel_map_t pin = try_find_pin_from_list( io_adc_maps);
}

#define PIN_STATE_TOKEN_IDX 2
void try_set_pin_state_based_on_input( char* read_buffer, jogwheel_map_t pin) 
{
    uint8_t pin_state_begin_idx = 0;
    uint8_t pin_state_end_idx = 0;

    if( str_get_token_indexes(  read_buffer, 
                                ' ', 
                                PIN_STATE_TOKEN_IDX,
                                &pin_state_begin_idx, 
                                &pin_state_end_idx)
        != SC_SUCCESS)
    {
        ASSERT(0);
        error_invalid_pin_state();
        return;
    }
        
    if( str_is_substring_of(read_buffer, "HIGH", pin_state_begin_idx) == SC_TRUE) 
    {
        gpio_set_high(pin.pin_number);
        return;
    }        
    if( str_is_substring_of(read_buffer, "LOW", pin_state_begin_idx) == SC_TRUE) 
    {
        gpio_set_low(pin.pin_number);
        return;
    }        
 
    error_invalid_pin_state();   
}

static void try_set_pin( char *read_buffer ) 
{
    jogwheel_map_t pin = try_find_pin_from_list( io_output_maps, read_buffer);
    
    if(pin.terminal_name != NULL)
    {
        try_set_pin_state_based_on_input( read_buffer, pin);
    }
    else
        error_invalid_pin();
}

void io_card_main_thread() {

    char read_buffer[15] = {0};

	while(1)
		{
			read_line(read_buffer, 15);
            
            // Command examples:
            // S 5.T0  H
            // S 5.T0  L
            // R 2.T0 
            // R 2.T0
            // A 1.T0         
            switch (read_buffer[0])
            {
            case 'S':
                try_set_pin(read_buffer);           
            	break;
            case 'R':
                try_read_pin(read_buffer);
                break;
            case 'A':
                try_get_pin_adc(read_buffer);
                break;
            default:
                error_invalid_command();
            }
		}
}