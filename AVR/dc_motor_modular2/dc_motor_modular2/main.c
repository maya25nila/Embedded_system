/*
 * dc_motor_modular2.c
 *
 * Created: 16-12-2025 11:30:17
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h"
#include "dcmotor.h"


int main(void)
{
    timer0_init();
	pwm_init();
    while (1) 
    {
		cw_motor(200);
		delay_ms(10000);
		stop();
		delay_ms(10000);
		
    }
}

