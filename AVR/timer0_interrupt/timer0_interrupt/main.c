/*
 * timer0_interrupt.c
 *
 * Created: 09-12-2025 21:46:34
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint16_t count=0;
ISR(TIMER0_OVF_vect)//interrupt vector table address for timer0 over flow
{
	if (count>977)
	{
		PORTB^=(1<<PB5);
		count=0;
		
	} 
	else
	{
		count++;
	}
}

int main(void)
{
	DDRB|=(1<<DDB5);
    sei();//ENABLE global interrupt 
	TCNT0=0;
	TCCR0A&=~((1<<WGM01)|(1<<WGM00));//for normal mode
	
	TCCR0B|=(1<<CS00)|(1<<CS01);//FOR CLK/64 PRESCALAR
	TCCR0B&=~(1<<CS02);
	
	TIMSK0|=(1<<TOIE0);//for timer0 overflow interrupt
    while (1) 
    {
    }
}

