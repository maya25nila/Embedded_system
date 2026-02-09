/*
 * pwm_led_dimming.c
 *
 * Created: 06-12-2025 16:13:05
 * Author : littles
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


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
   
   
   
   
   while (1)
   {
	   for(int i=0;i<=255;i++)
	   {
		   OCR0A=i;
		   _delay_ms(5);
	   }
	    for(int i=255;i>=0;i--)
	    {
		    OCR0A=i;
			_delay_ms(5);
	    }
	   
   }
   
}

