/*
 * dc_motor_modular.c
 *
 * Created: 08-12-2025 09:17:10
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "dcmotor.h"


int main(void)
{
    pwm_init();
    while (1) 
    {
		cw_motor(255);
		_delay_ms(5000);
		stop();
		_delay_ms(1000);
		cw_motor(150);
		_delay_ms(5000);
		stop();
		_delay_ms(1000);
    }
}

