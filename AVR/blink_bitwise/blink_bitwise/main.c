/*
 * blink_bitwise.c
 *
 * Created: 15-11-2025 20:31:36
 * Author : littles
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD|=(1<<DDD5);   //set DDRD5=1(PD5) as output
    while (1) 
    {
		PORTD=PORTD5 | (1<<PORTD5); //set PD5=1
		_delay_ms(1000);
		PORTD=PORTD5 & ~(1<<PORTD5);  //set PD5=0
		_delay_ms(1000);
    }
}

