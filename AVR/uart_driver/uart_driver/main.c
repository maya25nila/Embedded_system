/*
 * uart_driver.c
 *
 * Created: 13-01-2026 11:51:41
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include "uart_driver.h"


int main(void)
{
  UART_Init();
    while (1) 
    {
		UART_TxChar('$');
    }
}

