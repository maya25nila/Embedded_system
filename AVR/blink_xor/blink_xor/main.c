/*
 * blink_xor.c
 *
 * Created: 15-11-2025 20:52:33
 * Author : littles
 Blink using xor
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
# include <util/delay.h>


int main(void)
{
	DDRD^=(1<<DDD3);    //set DD3=1 as output
    
    while (1) 
    {
		PORTD=PORTD ^(1<<PORTD3); //set PD3=1
		_delay_ms(2000);
		PORTD=PORTD & ~(1<<PORTD3); //set PD3=0
		_delay_ms(2000);
    }
}

