/*
 * modular_timer0.c
 *
 * Created: 07-12-2025 11:35:59
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h"


int main(void)
{
    DDRB|=(1<<DDB5);
	timer0_init();
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_ms(3000);
    }
}

