/*
 * dcmotor.c
 *USING TIMER0
 * Created: 08-12-2025 09:28:47
 *  Author: littles
 */ 
#include<avr/io.h>
#include "dcmotor.h"
void pwm_init(void)
{
	DDRD|=(1<<DDD6);//pwm output pin SERVE AS motor +ve pin
	DDRD|=(1<<DDD7);//set as output pin
	PORTD&=~(1<<PD7);//PD7 always low other pin of motor
	
	
	
	TCCR0A|=(1<<WGM00); //configure for phase correct pwm
	TCCR0A&=~(1<<WGM01);
	
	TCCR0B&=~((1<<CS02)|(1<<CS00));//prescalar clk/8
	TCCR0B|=(1<<CS01);
	
	//configure in noninverting mode
	TCCR0A|=(1<<COM0A1);
	TCCR0A&=~(1<<COM0A0);
	
}
void stop(void)
{

		OCR0A=0;
}
void cw_motor(uint8_t duty_cycle)
{
	OCR0A=duty_cycle;
	
	}