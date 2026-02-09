/*
 * blink2pin_fun.c
 *
 * Created: 17-11-2025 12:15:22
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void cw(){
	PORTD|=(1<<PORTD1);
	PORTD=PORTD & ~(1<<PORTD4);
	}
void ccw(){
	PORTD|=(1<<PORTD4);
	PORTD=PORTD & ~(1<<PORTD1);
}
void stp()
{
	
	PORTD=PORTD & ~(1<<PORTD4);
	PORTD=PORTD & ~(1<<PORTD1);
}


int main(void)
{
	DDRD|=(1<<DDD1) | (1<<DDD4); //set PD1 and PD4 as output pin
    while (1) 
    {
		cw();  //pin PD1 on PD4 OFF
		_delay_ms(5000);
		stp();//PD1 and PD4 off
		_delay_ms(3000);
		ccw(); //PD4=on PD1=off
		_delay_ms(5000);
		stp();
		_delay_ms(3000);
    }
}

