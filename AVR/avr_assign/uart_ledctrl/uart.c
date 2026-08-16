#include<stdlib.h>
#include "uart.h"
void uart_TxRx_init()
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
char uart_char_rx(void)
{
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0;
}
void uart_string_rx(char *buffer, uint8_t max_len)
{
    uint8_t i = 0;
    char ch;

    while (1) {
        ch = (char)uart_char_rx();

        if (ch == '\r' || ch == '\n' || i >= max_len - 1) {
            buffer[i] = '\0';
            break;
        }

        buffer[i++] = ch;//put char in buffer and increment index
    }
    
}
/***
void uart_number_tx(uint8_t value)
{
    char buffer[4];

    itoa(value, buffer, 10);
    uart_string_tx(buffer);
}****/