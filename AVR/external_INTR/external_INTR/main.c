/*
 * external_INTR.c
 *
 * Created: 06-12-2025 20:19:51
 * Author : littles
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include<avr/interrupt.h>

#include<util/delay.h>
ISR(INT0_vect)  //external interrupt INT0
{
	PORTB^=(1<<PB5);  //toggling the PB5
	_delay_ms(10000);
	
}
int main(void)
{
	DDRD&=~(1<<DDD2); //set PD2 as input pin
	DDRB|=(1<<DDB5)|(1<<DDB4); //SET PB5,PB4 as output
	
	sei();//enable global interrupt pin
	EIFR|=(1<<INTF0);//CLEAR flag INTF0 IN the external interrupt flag register
    EIMSK|=(1<<INT0);//enable INT0 in EIMSK Register
	EICRA|=(1<<ISC01)|(1<<ISC00); //interrupt in rising edge
	
    while (1) 
    {
		PORTB&=~(1<<PB5);//PB5 low in normal
		PORTB^=(1<<PB4); //PB4 Flipping in normal
		_delay_ms(1000);
		
    }
}

