#ifndef UART_H
#define UART_H

#include <avr/io.h>

void uart_TxRx_init(void);
void uart_string_tx(char *str);
char uart_char_rx(void);
void uart_string_rx(char *bffer, uint8_t max_len);
//void uart_number_tx(uint8_t value);

#endif