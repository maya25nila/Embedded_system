#include "oled.h"
#include "i2c.h"
#include "font.h"
void oled_command(uint8_t cmd) {
  i2c_start();
  i2c_write(OLED_ADDR << 1);
  i2c_write(0x00);//for command
  i2c_write(cmd);
  i2c_stop();
}

void oled_data(uint8_t data) {
  i2c_start();
  i2c_write(OLED_ADDR << 1);
  i2c_write(0x40);//for data
  i2c_write(data);
  i2c_stop();
}

void oled_init(void) {
  /* Display OFF */
  oled_command(0xAE);

  /* Horizontal Addressing Mode */
  oled_command(0x20);
  oled_command(0x00);

  /* Page Start Address */
  oled_command(0xB0);

  /* COM Output Scan Direction */
  oled_command(0xC8);

  /* Lower Column Address */
  oled_command(0x00);

  /* Higher Column Address */
  oled_command(0x10);

  /* Display Start Line */
  oled_command(0x40);

  /* Contrast Control */
  oled_command(0x81);
  oled_command(0x7F);

  /* Segment Remap */
  oled_command(0xA1);

  /* Normal Display */
  oled_command(0xA6);

  /* Multiplex Ratio */
  oled_command(0xA8);
  oled_command(0x3F);

  /* Display Offset */
  oled_command(0xD3);
  oled_command(0x00);

  /* Oscillator Frequency */
  oled_command(0xD5);
  oled_command(0x80);

  /* Pre-Charge Period */
  oled_command(0xD9);
  oled_command(0xF1);

  /* COM Pins Hardware Config */
  oled_command(0xDA);
  oled_command(0x12);

  /* VCOM Detect Level */
  oled_command(0xDB);
  oled_command(0x40);

  /* Charge Pump Enable */
  oled_command(0x8D);
  oled_command(0x14);

  /* Display ON */
  oled_command(0xAF);
}

void oled_clear(void)
{
    uint8_t page;
    uint8_t col;

    for(page = 0; page < 8; page++)
    {
        oled_set_cursor(page, 0);

        for(col = 0; col < 128; col++)
        {
            oled_data(0x00);
        }
    }
}

void oled_set_cursor(uint8_t page, uint8_t column)
{
 column += 2;

    oled_command(0xB0 + page);
    oled_command(column & 0x0F);
    oled_command(0x10 | (column >> 4));
}
void oled_print_char(char ch)
{
    uint16_t index;

    index = ((uint8_t)ch) * 5;

    for(uint8_t i = 0; i < 5; i++)
    {
        oled_data(font[index + i]);
    }

    oled_data(0x00);
}
void oled_print(const char *str)
{
    while(*str)
    {
        oled_print_char(*str);
        str++;
    }
}
void oled_print_uint8(uint8_t value)
{
    if(value >= 10)
    {
        oled_print_uint8(value / 10);
    }

    oled_print_char('0' + (value % 10));
}
void oled_print_uint16(uint16_t value)
{
    if(value >= 10)
    {
        oled_print_uint16(value / 10);
    }

    oled_print_char('0' + (value % 10));
}

void oled_print_uint32(uint32_t value)
{
    if(value >= 10)
    {
        oled_print_uint32(value / 10);
    }

    oled_print_char('0' + (value % 10));
}