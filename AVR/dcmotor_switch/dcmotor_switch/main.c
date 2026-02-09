/*
 * dcmotor_switch.c
 *
 * Created: 22-11-2025 13:49:25
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{    //Configuration
    DDRD|=(1<<DDD1) |(1<<DDD2); //set 1 in PD1 AND PD2 to make output pin
	DDRC &=(~(1<<DDC1) | ~(1<<DDC2)); //SET 0 in PINC1,PINC2 to make input pin
	//DDRC &=~(1<<DDC2);
    while (1) 
    {
		if(PINC&(1<<PINC1) && !(PINC&(1<<PINC2)))// check pinc1=1 and PINC2=0
		{
			PORTD|=(1<<PORTD1); //PD1=ON
			PORTD&=~(1<<PORTD2);//PD2=OFF
		}
		else if(PINC & (1<<PINC2) && !(PINC & (1<<PINC1)))//CHECK PINC2=1 and PINC1=0
		{
			PORTD|=(1<<PORTD2);//PD2=ON
			PORTD&=~(1<<PORTD1);//PD1=OFF
			
		}
		else
		{
			PORTD &=~(1<<PORTD1);  //for all other condition PD1  and PD2  OFF
			PORTD &=~(1<<PORTD2);
		}
    
	}
}

