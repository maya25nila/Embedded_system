/*
 * blink2_pin.c
 *
 * Created: 15-11-2025 20:57:18
 * Author : littles
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{   DDRB|=(1<<DDB1);        //set  DDB1,DDB4 as output pin
	DDRB|=(1<<DDB4);
	
    while (1) 
    {     //PB1 ON and PB4 off
		PORTB|=(1<<PORTB1);
		PORTB=PORTB & ~(1<<PORTB4);
		_delay_ms(5000);
		//both PB1,PB4 off
		PORTB=PORTB & ~(1<<PORTB1);
		PORTB=PORTB & ~(1<<PORTB4);
		_delay_ms(3000);
		//PB1=OFF PB4 on
		PORTB=PORTB & ~(1<<PORTB1);
		PORTB|=(1<<PORTB4);
		_delay_ms(5000);
		//PB1 AND PB4 off
		PORTB=PORTB & ~(1<<PORTB1);
		PORTB=PORTB & ~(1<<PORTB4);
		_delay_ms(3000);
		
		
		
		
    }
}

