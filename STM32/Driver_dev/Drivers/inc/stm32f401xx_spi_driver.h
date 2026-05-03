/*
 * stm32f401xx_spi_driver.h
 *
 *  Created on: Mar 13, 2026
 *      Author: nilaNila
 */

#ifndef INC_STM32F401XX_SPI_DRIVER_H_
#define INC_STM32F401XX_SPI_DRIVER_H_

#include "stm32f401xx.h"

/* configuration structure for SPIx Peripherals ***/
typedef struct{
	uint8_t SPI_CPOL;    //
	uint8_t SPI_CPHA;    //
	uint8_t SPI_DevMode;  //to select master or slave mode
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_BusConfig;//to select full duplex/half duplex
	uint8_t SPI_DFF;    //for data register frame format 0 means 8 bit,1 means 16 bit
	uint8_t SPI_SSM;   //SLAVE SELECT

}SPI_Config;
typedef struct{
	SPI_RegDef *pSPIx;//structure ptr to  spi base address
	SPI_Config  SPI_Config_t;//structure config. variable
}SPI_Handle;

// DEVICE MODE
#define SPI_DEVICE_MODE_MASTER    1
#define SPI_DEVICE_MODE_SLAVE     0

// BUS CONFIGURATION
#define SPI_BUSCONFIG_FD               1
#define SPI_BUSCONFIG_HD               2
#define SPI_BUSCONFIG_SIMPLEX_RXONLY   3

//BUS CLK SPEED
#define SPI_CLK_SPEED_DIV2         0
#define SPI_CLK_SPEED_DIV4         1
#define SPI_CLK_SPEED_DIV8         2
#define SPI_CLK_SPEED_DIV16        3
#define SPI_CLK_SPEED_DIV32        4
#define SPI_CLK_SPEED_DIV64        5
#define SPI_CLK_SPEED_DIV128       6
#define SPI_CLK_SPEED_DIV256       7

//dff
#define SPI_DFF_8BIT           0
#define SPI_DFF_16BIT          1


//CPOL
#define SPI_CPOL_LOW   0
#define SPI_CPOL_HIGH  1

//CPHA

#define SPI_CPHA_LOW	0
#define SPI_CPHA_HIGH	1

//SPI SSM
#define SPI_SSM_EN    1
#define SPI_SSM_DI    0

//for flag
#define SPI_TXE_FLAG            (1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG           (1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG           (1 << SPI_SR_BSY)
//API
void SPI_PeriClockControl(SPI_RegDef *pSPIx,uint8_t EnorDi);
void SPI_Init(SPI_Handle *pSPIHandle);
void SPI_DeInit(SPI_RegDef *pSPIx);
void SPI_SendData(SPI_RegDef *pSPIx,uint8_t *pTxBuffer,uint32_t len);
void SPI_ReceiveData(SPI_RegDef *pSPIx,uint8_t *pRxBuffer,uint32_t len);




#endif /* INC_STM32F401XX_SPI_DRIVER_H_ */
