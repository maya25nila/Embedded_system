/*
 * UART.c
 *
 * Created: 01-01-2026 15:01:02
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void UART_TX_init(void)
{
	UBRR0H=0;
	UBRR0L=103;//for set the baud rate 9600
	
	UCSR0B|=(1<<TXEN0);//for Txion  Enable
	
	UCSR0C&=~((1<<UMSEL01)|(1<<UMSEL00));//asynchronous mode
	UCSR0C&=~((1<<UPM01)|(1<<UPM00));//for no parity
	UCSR0C&=~(1<<USBS0);//for 1 stop bit
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);//for 8 bit data mode
}


int main(void)
{
    UART_TX_init();
    while (1) 
    {
	
		while(!(UCSR0A &(1<<UDRE0)));//when  transmission complete UDRE0=1 Means UDR0 empty ready for next transmission
			UDR0='A';
			_delay_ms(1000);
							
    }
}


