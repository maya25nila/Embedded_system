/*
 * uart_driver.h
 *
 * Created: 13-01-2026 11:54:02
 *  Author: littles
 */ 


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include <avr/io.h>
#include <stdlib.h>

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)

// === Function Prototypes ===
void UART_Init(void);
void UART_TxChar(char data);
void UART_TxString(const char *str);
void UART_TxHex(uint8_t value);
void UART_TxNumber(uint32_t num);
void UART_Txfloat(float num);

#endif /* UART_DRIVER_H_ */