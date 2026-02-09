/*
 * pwm_delay.c
 *
 * Created: 29-11-2025 21:07:55
 * Author : littles
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRD|=(1<<DDD6);//PWM output in PD6 so configure PD6 as output pin
	
		
	//PWM IN phase correct mode
	TCCR0A|=(1<<WGM00); 
	TCCR0A&=~(1<<WGM01);
	
	//FOR pwm in non inverting
	TCCR0A|=(1<<COM0A1);  
	TCCR0A&=~(1<<COM0A0);
	
	//for prescalar clk/8
	TCCR0B|=(1<<CS01);
	TCCR0B&=~(1<<CS00); 
	TCCR0B&=~(1<<CS02);
	
	OCR0A=128; //for 50% duty cycle
	
   
    while (1) 
    {
    }
}

