/*
 * traffic_onedir.c
 *
 * Created: 20-11-2025 12:03:37
 * Author : littles
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void red_Light(){
	PORTB |=(1<<PORTB1); //set PB1=1 for red
	PORTB &=~(1<<PORTB2);//PB2 =0as yellow
	PORTB &=~(1<<PORTB3);//PB3=0 as green
}
void green_Light(){
	PORTB |=(1<<PORTB3); //set PB3=1 for green
	PORTB &=~(1<<PORTB2);//PB2 =0 for yellow
	PORTB &=~(1<<PORTB1);//PB1=0 for red
}
void yellow_Light(){
	PORTB |=(1<<PORTB2); //set PB1=1 for yellow
	PORTB &=~(1<<PORTB1);//PB2 =0as red
	PORTB &=~(1<<PORTB3);//PB3=0 as green
}


int main(void)
{
   DDRB|=(1<<DDB1)|(1<<DDB2)|(1<<DDB3);//SET PB1=PB2=PB3=1 as output pin
    while (1) 
    {
		red_Light();
		_delay_ms(5000);
		yellow_Light();
		_delay_ms(2000);
		green_Light();
		_delay_ms(5000);
    }
}

