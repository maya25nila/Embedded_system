/*
 * spi.c
 *
 * Created: 06-01-2026 20:42:53
 * Author : littles
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include<util/delay.h>
#include "uart_driver.h"
void spi_init()
{
	DDRB|=(1<<DDB3)|(1<<DDB5)|(1<<DDB2);//MOSI,SCK,SS configured as O/P PIN
	DDRB&=~(1<<DDB4);//MISO config. as  i/p pin
	//configure SPCR
	SPCR=0;//CLEARING
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);//spi enable,master select ,spi clk rate fosc/16
	SPCR&=~((1<<CPOL)|(1<<CPHA)|(1<<SPR1));//0 mode
	SPSR=0;//change made	  
}


int main(void)
{
	uint8_t chip_id,msb,lsb,xlsb;
	uint8_t T1_lsb,T1_msb,T2_lsb,T2_msb;
	uint8_t T3_lsb,T3_msb;
	uint32_t temp;
	uint16_t dig_T1,dig_T2;
	int16_t dig_T3;
	float var1,var2,t_fine,Temperature;
	spi_init();
	UART_Init();
   _delay_ms(10);//power up delay -change 
  
    while (1) 
    {
		 PORTB&=~(1<<PB2);//SELECTING slave
		 _delay_us(2);//-change
		 SPDR=(0XD0|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		 while (!(SPSR&(1<<SPIF)));//waiting until flag set
		 (void)SPDR;//reading SPDR(for dummy garbage value)
		 
		 SPDR=0X00;//sending dummy to read data from BMP280
		 while(!(SPSR&(1<<SPIF)));
		 chip_id=SPDR;//reading real chip id
		 PORTB|=(1<<PB2);//deselecting slave
		 UART_TxHex(chip_id);
		 _delay_ms(1000);		
		
		//temperature reading
		//Enable BMP280 for temperature sensing(wake up from sleep mode)
	PORTB&=~(1<<PB2);//SELECTING slave
	SPDR=(0XF4 & 0X7F);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
	while (!(SPSR&(1<<SPIF)));//waiting until flag set
	(void)SPDR;//reading SPDR(for dummy garbage value)
	
	SPDR=0X27;//writing 0x27 to enable BMP280
	while(!(SPSR&(1<<SPIF)));
	
	PORTB|=(1<<PB2);//deselecting slave
	
		
		//first reading msb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0XFA|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading SPDR(for dummy garbage value)
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		msb=SPDR;//reading msb
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading LSB
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0XFB|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading SPDR(for dummy garbage value)
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		lsb=SPDR;//reading msb
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading xlsb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0XFC|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading SPDR(for dummy garbage value)
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		xlsb=SPDR;//reading msb
		PORTB|=(1<<PB2);//deselecting slave
		
		temp=((uint32_t)msb<<12) | ((uint32_t)lsb<<4) | ((uint32_t)xlsb>>4);
		UART_TxString("temperature:");
		UART_TxNumber(temp);
		_delay_ms(1000);
		UART_TxChar('\r');
		UART_TxChar('\n');
		
		//Reading 3 temperature compensation values of 16 bit data
		
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X88|0X80);// read lsb, 0x88 address of lsb
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading SPDR(for dummy garbage value)
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T1_lsb=SPDR;//reading lsb
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading T1 msb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X89|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading S
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T1_msb=SPDR;//reading msb
		dig_T1=((uint16_t)T1_msb<<8)|(uint16_t)T1_lsb;
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading T2lsb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X8A|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading S
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T2_lsb=SPDR;//reading T2 lsb
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading T2 msb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X8B|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading S
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T2_msb=SPDR;//reading msb
		dig_T2=((uint16_t)T2_msb<<8)|(uint16_t)T2_lsb;
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading T3lsb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X8C|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading S
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T3_lsb=SPDR;//reading T3 lsb
		PORTB|=(1<<PB2);//deselecting slave
		
		//reading T3 msb
		PORTB&=~(1<<PB2);//SELECTING slave
		SPDR=(0X8D|0X80);//0xD0 address of chip id of BMP 280 and ENSURING msb 1 for read operation
		while (!(SPSR&(1<<SPIF)));//waiting until flag set
		(void)SPDR;//reading S
		
		SPDR=0X00;//sending dummy to read data from BMP280
		while(!(SPSR&(1<<SPIF)));
		T3_msb=SPDR;//reading T2 ls
		PORTB|=(1<<PB2);//deselecting slave
		
		dig_T3=((int16_t)T3_msb<<8)|(int16_t)T3_lsb;
		
		UART_TxNumber(dig_T1);
		UART_TxChar('\r');
		UART_TxChar('\n');
		_delay_ms(1);
		
		UART_TxNumber(dig_T2);
		UART_TxChar('\r');
		UART_TxChar('\n');
		_delay_ms(1);
		UART_TxNumber(dig_T3);
		UART_TxChar('\r');
		UART_TxChar('\n');
		_delay_ms(1);
		//actual temperature
		var1=((temp/16384.0f)-(dig_T1/1024.0f))*dig_T2;
		var2=((temp/16384.0f)-(dig_T2/8192.0f))*dig_T3;
		t_fine=var1+var2;
		Temperature=(t_fine/5120.0f);
		 UART_TxString("Temperature");
		 UART_Txfloat(Temperature);
		 UART_TxChar('\n');
		
		
	}
}

