/*
 * timer0.c
 *
 * Created: 25-11-2025 21:33:00
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
delay_1s()
{
	TCNT0=0;  //load min value
	//for Normal mode
	TCCR0A&=~((1<<WGM00) | (1<<WGM01)); //WGM00 6TH bit,WGM01 3RD bit 0 for normal mode
	//SET no prescaling ,works in clock frequency
	TCCR0B&=~((1<<CS02)|(1<<CS01)); //CS02,CS01=0
	TCCR0B|=(1<<CS00);//CS00=1 for no prescaling
	for (long int i=0;i<62500;i++)
	{
	
	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	}
}


int main(void)
{
DDRB|=(1<<DDB5);    
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

