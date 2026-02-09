/*
 * led_normallypushup.c
 *
 * Created: 22-11-2025 21:13:19
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>



int main(void)
{      //configuration
	DDRD&=~(1<<DDD1);//DD1=0 SET DD1 AS INPUT pin
	DDRC|=(1<<DDC2);// DC2 =1 set DC2 as output pin
    while (1) 
    {
		if(!(PIND&(1<<PIND1)))//FOR normally pulled up check PIN1=0
		{
			PORTC|=(1<<PORTC2); //PORTC2 =1 and LED ON
		}
		else
		{
			PORTC&=~(1<<PORTC2);//PORTC2 =0 and LED OFF
		}
    }
}

