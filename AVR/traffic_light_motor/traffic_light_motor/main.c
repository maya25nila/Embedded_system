/*
 * traffic_light_motor.c
 *
 * Created: 23-11-2025 19:43:33
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
void green()  //for green light
{
	PORTC|=(1<<PORTC1);
	PORTC&=~(1<<PORTC2);
	PORTC&=~(1<<PORTC3);
}

void orange()  //for orange light
{
	PORTC|=(1<<PORTC2);
	PORTC&=~(1<<PORTC1);
	PORTC&=~(1<<PORTC3);
}
void red()  //for red light
{
	PORTC|=(1<<PORTC3);
	PORTC&=~(1<<PORTC1);
	PORTC&=~(1<<PORTC2);
}
 cw()
 {                        //motor rotate clockwise direction
	 PORTB|=(1<<PORTB2);
	 PORTB&=~(1<<PORTB1);
 }

void stp()
{
	  //motor stop
	PORTB&=~(1<<PORTB2);
	PORTB&=~(1<<PORTB1);
}
void ccw()
	{       //motor rotate anticlockwise direction
		
		PORTB|=(1<<PORTB1);
		PORTB&=~(1<<PORTB2);
	}

int main(void)
{
 //configuration
DDRD&=~(1<<DDD1); //PIND1=0 as input CONNECTED TO SWITCH
 
 DDRC|=(1<<DDC1); //PC1=1 output for green
 DDRC|=(1<<DDC2);//PC2=1 output for orange
 DDRC|=(1<<DDC3);//PC1=1 output for red
 
DDRB|=(1<<DDB1);//PB1=1 output for motor
DDRB|=(1<<DDB2);//PB2=1 output for motor
    while (1) 
    {
		green();
		if(!(PIND&(1<<PIND1)))
		{  
			cw();
			red();
			_delay_ms(10000);
			stp();
			_delay_ms(2000);
		    ccw();
			_delay_ms(10000);
			stp();
			_delay_ms(1000);
			green();
			
		}
		
		_delay_ms(5000);
		orange();
		_delay_ms(2000);
		red();
		_delay_ms(5000);
		orange();
		_delay_ms(2000);
		
    }
}

