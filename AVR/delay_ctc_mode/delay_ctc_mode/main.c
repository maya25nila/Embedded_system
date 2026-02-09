/*
 * delay_ctc_mode.c
 *
 * Created: 27-11-2025 21:07:44
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1sCTC(void)
{
	TCNT0=0;//initial value of counter
	OCR0A=199;//SET point for 200 count
	TCCR0A&=~(1<<WGM00);//CTC mode WGM01=1,WGM00=0
	TCCR0A|=(1<<WGM01);
	
	TCCR0B&=~(1<<CS02);//for no pre scaling CS00=1,CS01=0,CS02=0
	TCCR0B&=~(1<<CS01);
	TCCR0B|=(1<<CS00);
	
	for(long int i=0;i<80000;i++)
	{
		while(!(TIFR0&(1<<OCF0A)));//repeat loop until OCF0A FLAG set
		TIFR0|=(1<<OCF0A);//clear the flag OCF0A by writing 1
	}
	
	}


int main(void)
{
   DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		delay_1sCTC();
    }
}

