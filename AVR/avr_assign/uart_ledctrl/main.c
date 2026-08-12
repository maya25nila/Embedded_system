#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "uart.h"
int main(void)
{
  uart_TxRx_init();
  uart_string_tx("LED Light Control");
  uart_string_tx("\n");
  uart_string_tx("on : on");
  uart_string_tx("off : off");
  uart_string_tx("Brightness 0-100");
 
    while (1) 
    {
		  uart_string_tx("Enter command");
      uart_Rx();
    }
}