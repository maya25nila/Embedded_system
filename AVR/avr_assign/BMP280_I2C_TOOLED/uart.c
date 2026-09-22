#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

#include "uart.h"
#include<stdlib.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)


/* ==================================================
   UART INITIALIZATION
   ================================================== */

void UART_Init(void)
{
    /*
     * Set baud rate to 9600
     *
     * F_CPU = 16 MHz
     *
     * UBRR = 103
     */

    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;


    /*
     * Enable transmitter and receiver
     */

    UCSR0B =
        (1 << RXEN0) |
        (1 << TXEN0);


    /*
     * Frame format:
     *
     * 8 data bits
     * No parity
     * 1 stop bit
     */

    UCSR0C =
        (1 << UCSZ01) |
        (1 << UCSZ00);
}


/* ==================================================
   TRANSMIT ONE CHARACTER
   ================================================== */

void UART_TxChar(char data)
{
    /*
     * Wait until transmit buffer is empty.
     */

    while (!(UCSR0A & (1 << UDRE0)));

    /*
     * Put character into transmit register.
     */

    UDR0 = data;
}


/* ==================================================
   TRANSMIT STRING
   ================================================== */

void UART_TxString(const char *str)
{
    while (*str)
    {
        UART_TxChar(*str);
        str++;
    }
}


/* ==================================================
   TRANSMIT HEXADECIMAL VALUE
   ================================================== */

void UART_TxHex(uint8_t value)
{
    const char hex[] = "0123456789ABCDEF";

    /*
     * Upper 4 bits
     */

    UART_TxChar(hex[(value >> 4) & 0x0F]);

    /*
     * Lower 4 bits
     */

    UART_TxChar(hex[value & 0x0F]);
    
}
void UART_TxNumber(uint32_t num)
 {
 char buffer[12];
 ltoa(num, buffer, 10);   // convert to string (long to ASCII)
 UART_TxString(buffer);
 }
void uart_clear(void)
    {
        UART_TxString("\033[2J\033[H");
    }