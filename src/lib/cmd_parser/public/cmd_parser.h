/*
 * cmd_parser.h
 *
 * Created: 6.4.2012 13:55:36
 *  Author: savpek
 */


#ifndef CMD_PARSER_H_
#define CMD_PARSER_H_

extern statusc_t cmd_parse_get_target( char *in_source_str, uint8_t *out_target_id);

extern statusc_t cmd_parse_get_command( char *in_source_str);

extern statusc_t cmd_parse_get_value( char *in_source_str, uint8_t *out_target_value);

#endif /* CMD_PARSER_H_ */