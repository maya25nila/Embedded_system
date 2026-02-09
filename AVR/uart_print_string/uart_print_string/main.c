/*
 * uart_print_string.c
 *
 * Created: 08-01-2026 14:44:16
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart_print_string.h"


int main(void)
{
    UART_TX_init();
	
    while (1) 
    {
		uart_string_tx("Hello");
		_delay_ms(2000);
		uart_string_tx("\n");
		_delay_ms(1000);
		
    }
}

