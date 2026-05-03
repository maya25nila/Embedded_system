/*
 * stm32f401xx_spi_driver.c
 *
 *  Created on: Mar 13, 2026
 *      Author: nilaNila
 */
#include "stm32f401xx.h"
#include "stm32f401xx_spi_driver.h"

/*********************************************************************
 * @fn          - SPI_PeriClockControl
 *
 * @brief       - Enables or disables peripheral clock for SPI
 *
 * @param[in]   - pSPI: SPI base address
 * @param[in]   - EnorDi: ENABLE or DISABLE macros
 *
 * @return      - none
 *
 * @Note        - refer CLOCK ENABLE or DISABLE Macros
 *********************************************************************/

void SPI_PeriClockControl(SPI_RegDef *pSPIx,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(pSPIx==SPI1)
		{
			SPI1_CLK_EN();
		}
		else if(pSPIx==SPI2)
		{
			SPI2_CLK_EN();
		}
		else if(pSPIx==SPI3)
				{
					SPI3_CLK_EN();
				}
		else if(pSPIx==SPI4)
				{
					SPI4_CLK_EN();
				}

	}
	//for DISABLE CLOCK
	else
	   {
		if(pSPIx==SPI1)

	     {
		  SPI1_CLK_DIS();
	     }
	  else if(pSPIx == SPI2)
	     {
		    SPI2_CLK_DIS();
	      }
	  else if(pSPIx == SPI3)
			{
				SPI3_CLK_DIS();
			}
	  else if(pSPIx == SPI4)
			{
				SPI4_CLK_DIS();
			}

	   }
}

void SPI_Init(SPI_Handle *pSPIHandle)
{
	SPI_PeriClockControl(pSPIHandle->pSPIx,ENABLE);
	uint32_t tempreg=0;
	tempreg|=pSPIHandle->SPI_Config_t.SPI_DevMode<<SPI_CR1_MSTR ;//config.device mode
	if(pSPIHandle->SPI_Config_t.SPI_BusConfig==SPI_BUSCONFIG_FD)
	{
		tempreg &=~(1<<SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPI_Config_t.SPI_BusConfig==SPI_BUSCONFIG_HD){
		tempreg|=(1<<SPI_CR1_BIDIMODE);
	}

	else if(pSPIHandle->SPI_Config_t.SPI_BusConfig==SPI_BUSCONFIG_SIMPLEX_RXONLY){
		tempreg &=~ (1<<SPI_CR1_BIDIMODE);
		tempreg |=(1<<SPI_CR1_RXONLY);
	}
 tempreg |= pSPIHandle->SPI_Config_t.SPI_SclkSpeed<<SPI_CR1_BR;
 tempreg |= pSPIHandle->SPI_Config_t.SPI_CPHA<<SPI_CR1_CPHA;
 tempreg |= pSPIHandle->SPI_Config_t.SPI_CPOL<<SPI_CR1_CPOL;
 tempreg |= pSPIHandle->SPI_Config_t.SPI_DFF<<SPI_CR1_DFF;
 pSPIHandle->pSPIx->CR1 = tempreg;

}
void SPI_DeInit(SPI_RegDef *pSPIx){

}
uint8_t SPI_GetFlagStatus(SPI_RegDef *pSPIx,uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
		return FLAG_SET;
	else
		return FLAG_RESET;
}
void SPI_SendData(SPI_RegDef *pSPIx,uint8_t *pTxBuffer,uint32_t len){
	while(len){
		//WAIT UNTIL TXE FLAG SET(TX Buffer empty)
     while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)==FLAG_RESET);
     if((pSPIx->CR1 & (1 << SPI_CR1_DFF)))//for 16 bit DATA DFF=1
     {
    	 pSPIx->DR=*(uint16_t*)pTxBuffer;
    	 len--;//one byte decrement
    	 len--;
    	 (uint16_t*)pTxBuffer++;

     }
     //for 8 bit data DFF=0
     else
     {
    	 pSPIx->DR=*pTxBuffer;
          len--;
    	  (uint16_t*)pTxBuffer++;
     }
	}
}
void SPI_ReceiveData(SPI_RegDef *pSPIx,uint8_t *pRxBuffer,uint32_t len){
	while(len){
			//WAIT UNTIL RXNE FLAG SET(RX Buffer not empty)
	     while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG)==FLAG_RESET);
	     if((pSPIx->CR1 & (1 << SPI_CR1_DFF)))//for 16 bit DATA DFF=1
	     {
	    	 *(uint16_t*)pRxBuffer=pSPIx->DR;
	    	 len--;//one byte decrement
	    	 len--;
	    	 (uint16_t*)pRxBuffer++;

	     }
	     //for 8 bit data DFF=0
	     else
	     {
	    	 *pRxBuffer= pSPIx->DR;
	          len--;
	    	  pRxBuffer++;
	     }
		}

}

