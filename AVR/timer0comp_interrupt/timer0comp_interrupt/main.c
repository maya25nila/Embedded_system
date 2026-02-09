/*
 * timer0comp_interrupt.c
 *
 * Created: 11-12-2025 20:24:40
 * Author : littles
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>
volatile uint8_t count=0;
ISR (TIMER0_COMPA_vect)
{
	if (count>250)
	{
	
	PORTD^=(1<<PD5);
	count=0;
	}
	else
	{
		count++;
	}
}

int main(void)
{
	DDRD|=(1<<DDD5);
    sei();
	TCNT0=0;//set TIMER0 initial value 0
	TCCR0A|=(1<<WGM01);//configure for CTC mode
	TCCR0A&=~(1<<WGM00);
	
	OCR0A=249;//set point
	TCCR0B&=~((1<<CS00)|(1<<CS01));//prescalar 256
	TCCR0B|=(1<<CS02);
	
	TIMSK0|=(1<<OCIE0A);//TIMSK0 MASK register OCIE0A bit set for compare mode
	
    while (1) 
    {
    }
}

