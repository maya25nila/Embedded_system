/*
 * switch_interface.c
 *
 * Created: 20-11-2025 20:07:34
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{       //configuration
    DDRB |=(1<<DDB5); //DDB5 as output pin-DB5=1
	DDRD &=~(1<<DDD2);//DDD2 as input pin -DDD2=0
    while (1) 
    {
		if(PIND & (1<<PIND2))  //check for PD2=1
		{
			PORTB|=(1<<PORTB5); //PB5=1 for true and Led ON
		}
		else
		{
			PORTB &=~(1<<PORTB5);//PB5=0 for false and Led OFF
		}
    }
}

