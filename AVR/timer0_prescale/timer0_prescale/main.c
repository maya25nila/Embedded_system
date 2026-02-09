/*
 * timer0_prescale.c
 *
 * Created: 27-11-2025 20:26:30
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1spre1024()
{
	TCNT0=0;
	TCCR0A&=~((1<<WGM00) |(1<<WGM01));//normal mode
	
	TCCR0B&=~(1<<CS01); //for pre scalar 1024
	TCCR0B|=(1<<CS02)|(1<<CS00);
	for(long int i=0;i<=61;i++)
	{
		while(!(TIFR0&(1<<TOV0)));
		TIFR0|=(1<<TOV0);//write 1 to TOV0 TO MAKE IT CLEAR
	}
}
	int main(void)
	{
		DDRB|=(1<<DDB5);
		while(1)
		{
			PORTB^=(1<<PORTB5);
			delay_1spre1024();
		}
	}



