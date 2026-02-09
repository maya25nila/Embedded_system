/*
 * LM35_adc.c
 *
 * Created: 07-01-2026 11:39:30
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include "lcd.h"
void adc_init(void)
{
	ADMUX|=(1<<REFS0);//ADC reference voltage 5v
	ADMUX&=~((1<<REFS1)|(1<<ADLAR));
	
	ADCSRA|=(1<<ADEN);//ENABLE adc
	//prescalar clk/128
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	
}
uint16_t adc_read(uint8_t channel)
{
  	
  channel&=0x07;//limits channel selection to 7
  ADMUX=(ADMUX&0XF0)|channel;//Selecting channel
  ADCSRA|=(1<<ADSC);//adc start conversion
  while(ADCSRA&(1<<ADSC));
  return(ADCL|(ADCH<<8));
  	
}


int main(void)
{
    uint16_t value;
	float temp;
	adc_init();
	lcd_init();
	
    while (1) 
    {
		value=adc_read(0);
		temp=value*0.488;//converting adc voltage to temperature
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature:");
		lcd_set_cursor(1,0);
		lcd_print_float(temp);
		lcd_data(0xDF);
		lcd_print("c");
		_delay_ms(500);
		
    }
}

