
#include "uart.h"
uart_TxRx_init()
{
    UBRR0H=0;
    UBRR0L=103;//SET BOUD Rate to 9600
    UCSR0C |= ((1<<UCSZ01) | (1<<UCSZ00));//8 bit data
    UCSR0C &=~ ((1<<UPM00) | (1<<UPM01) | (1<<USBS0));//NO PARITY AND 1 stop bit
    UCSR0B |= ((1<<TXEN0) | (1<<RXEN0));//for transmission  and reception enable
}

void uart_string_tx(char *str)
{
	
     while(*str)
	 {
	  while(!(UCSR0A&(1<<UDRE0)));//CHECK  TXION COMPLETE for every char 
     	UDR0=*str;//
	    str++;//increment address
	 }
	
}
void uart_Rx()
{
    while()
}