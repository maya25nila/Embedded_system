/*
 * pwm_30dutycycle.c
 *
 * Created: 06-12-2025 16:28:27
 * Author : littles
 */ 

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
    
    OCR0A=77; //for 30% duty cycle
    
    while (1) 
    {
    }
}

