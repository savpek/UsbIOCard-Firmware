#include "framework.h"
#include "app/io_card_main/config/io_card_mapping.h"

const char *error_msg_header = "ERROR: ";

static void error_invalid_command()
{
    print_string(error_msg_header);
    print_line("Invalid command!");
}

static void error_invalid_pin()
{
    print_string(error_msg_header);
    print_line("Invalid pin!");
}

static void error_invalid_pin_state()
{
    print_string(error_msg_header);
    print_line("Invalid pin state!");
}

static statusc_t is_token_equal_to(char* input_buffer, char* test_this_string, uint8_t token_idx)
{
    uint8_t begin_idx = 0;
    uint8_t end_idx = 0;

    if( str_get_token_indexes(  input_buffer, 
                                ' ', 
                                token_idx,
                                &begin_idx, 
                                &end_idx)
        != SC_SUCCESS)
    {
        ASSERT(0);
        SC_FALSE;
    }
        
    if( str_is_substring_of(input_buffer, test_this_string, begin_idx) == SC_TRUE) 
    {
        return SC_TRUE;
    }
    
    return SC_FALSE;
}

#define PIN_STRING_TOKEN_IDX 1
static jogwheel_map_t try_find_pin_from_list(jogwheel_map_t *list, char* read_buffer)
{
    for(uint8_t i = 0; list[i].terminal_name != NULL; i++)
    {
        if(is_token_equal_to(read_buffer, list[i].terminal_name, PIN_STRING_TOKEN_IDX) == SC_TRUE)
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
    if( is_token_equal_to(read_buffer, "HIGH", PIN_STATE_TOKEN_IDX) == SC_TRUE) 
    {
        gpio_set_high(pin.pin_number);
        return;
    }        
    if( is_token_equal_to(read_buffer, "LOW", PIN_STATE_TOKEN_IDX) == SC_TRUE) 
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

#define COMMAND_TOKEN_IDX 0
void io_card_main_thread() {

    char read_buffer[20] = {0};

	while(1)
		{
			read_line(read_buffer, 20);
            
            if( is_token_equal_to(read_buffer, "SET", COMMAND_TOKEN_IDX) )
            {
                try_set_pin(read_buffer);
                continue;
            }            
            
            if( is_token_equal_to(read_buffer, "READ", COMMAND_TOKEN_IDX) )
            {
                try_read_pin(read_buffer);
                continue;
            }            
            
            if( is_token_equal_to(read_buffer, "READ_ADC", COMMAND_TOKEN_IDX) )
            {
                try_get_pin_adc(read_buffer);
                continue;
            }            
            
            error_invalid_command();
		}
}