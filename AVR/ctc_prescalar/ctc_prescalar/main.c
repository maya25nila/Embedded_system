/*
 * ctc_prescalar.c
 *
 * Created: 29-11-2025 23:31:09
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1sCTC_prescalar(void)
{
	TCNT0=0;
	OCR0A=199;//SET point for 200 count
	TCCR0A&=~(1<<WGM00);//CTC mode WGM01=1,WGM00=0
	TCCR0A|=(1<<WGM01);
	
	TCCR0B|=(1<<CS02);//for 1024 pre scaling CS00=1,CS01=0,CS02=1
	TCCR0B&=~(1<<CS01);
	TCCR0B|=(1<<CS00);
	
	for(long int i=0;i<78;i++)
	{
		while(!(TIFR0&(1<<OCF0A)));
		TIFR0|=(1<<OCF0A);
	}
	
}


int main(void)
{
	DDRB|=(1<<DDB5);
	while (1)
	{
		PORTB^=(1<<PORTB5);
		delay_1sCTC_prescalar();
	}
}



