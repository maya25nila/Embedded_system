/*




command = 0x00 
data = 0x40 



*/

#ifndef OLED_H_
#define OLED_H_

#include <avr/io.h>
#include <stdint.h>

#define OLED_ADDR 0x3C

void oled_init(void);
void oled_command(uint8_t cmd);
void oled_data(uint8_t data);
void oled_clear(void);
void oled_set_cursor(uint8_t page, uint8_t column);
void oled_print(const char *str);
void oled_print_uint8(uint8_t value);
void oled_print_uint16(uint16_t value);
void oled_print_uint32(uint32_t value);
void oled_print_char(char ch);

#endif