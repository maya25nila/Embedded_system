/*
 * delay.c
 *
 * Created: 07-12-2025 19:37:52
 *  Author: littles
 */ 
#include<avr/io.h>
#include "delay.h"
void timer0_init(void)
{
	//timer0 configuration
	TCNT0=0;
	OCR0A=249; //SET POINT
	
	//CTC mode
	TCCR0A|=(1<<WGM01); 
	TCCR0A&=~(1<<WGM00);
	
	//prescalar clk/64
	TCCR0B|=(1<<CS01)|(1<<CS00);
	TCCR0B&=~(1<<CS02);
}
	
	
void delay_ms(uint16_t ms)
{	
	while(ms--)
	{
		
	while(!(TIFR0&(1<<OCF0A)));//delay for 1ms
	TIFR0|=(1<<OCF0A);
	}
}