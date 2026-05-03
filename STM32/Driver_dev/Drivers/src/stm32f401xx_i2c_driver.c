/*
 * stm32f401xx_i2c_driver.c
 *
 *  Created on: Apr 13, 2026
 *      Author: nilaNila
 */

#include "stm32f401xx.h"

 static void I2C_ClearADDRFlag(I2C_Handle *pI2CHandle);
 static void I2C_ExecuteAddressPhase_Write(I2C_RegDef *pI2Cx,uint8_t SubNodeAddr);
 uint8_t I2C_GetFlagStatus(I2C_RegDef *pI2Cx,uint32_t FlagName);

 static void I2C_ClearADDRFlag(I2C_Handle *pI2CHandle) //clear ADDR by reading SR1 and SR2
 {
 	uint32_t dummy_read;
 	dummy_read=pI2CHandle->pI2Cx->SR1;
 	dummy_read=pI2CHandle->pI2Cx->SR2;
 	(void)dummy_read;


 }
 uint8_t I2C_GetFlagStatus(I2C_RegDef *pI2Cx,uint32_t FlagName){
 	if(pI2Cx->SR1 & FlagName)
 	{
 		return FLAG_SET;
 	}
 	 return FLAG_RESET;
 }
 static void I2C_ExecuteAddressPhase_Write(I2C_RegDef *pI2Cx,uint8_t SubNodeAddr)
 {
 	SubNodeAddr = (SubNodeAddr << 1);
 	SubNodeAddr &= ~(1);
 	pI2Cx->DR=SubNodeAddr;
 }
/*********************************************************************
 * @fn          - I2C_PeriClockControl
 *
 * @brief       - Enables or disables peripheral clock for I2C
 *
 * @param[in]   - pI2C: I2C base address
 * @param[in]   - EnorDi: ENABLE or DISABLE macros
 *
 * @return      - none
 *
 * @Note        - refer CLOCK ENABLE or DISABLE Macros
 *********************************************************************/

void I2C_PeriClockControl(I2C_RegDef *pI2Cx,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(pI2Cx==I2C1)
		{
			I2C1_CLK_EN();
		}
		else if(pI2Cx==I2C2)
		{
			I2C2_CLK_EN();
		}
		else if(pI2Cx==I2C3)
				{
					I2C3_CLK_EN();
				}


	}
	//for DISABLE CLOCK
	else
	   {
		if(pI2Cx==I2C1)

	     {
		  I2C1_CLK_DIS();
	     }
	  else if(pI2Cx == I2C2)
	     {
		    I2C2_CLK_DIS();
	      }
	  else if(pI2Cx == I2C3)
			{
				I2C3_CLK_DIS();
			}

	   }
}
/*********************************************************************
 * @fn          - I2C_Init
 *
 * @brief       - function for read value from I2C
 *
 * @param[in]   - pI2C: I2C base address

 * @return      - none
 *
 * @Note        - refer I2C Register config.Register
 *********************************************************************/

void I2C_Init(I2C_Handle *pI2CHandle)
{
	uint32_t tempreg=0;

	 I2C_PeriClockControl(pI2CHandle->pI2Cx,ENABLE);

	 tempreg|=pI2CHandle->I2C_Config_t.I2C_AckControl<<10;//
	 pI2CHandle->pI2Cx->CR1=tempreg;

	 //configure the FREQ field of CR2
	 tempreg=0;
      //PCLK 16000000 IN APB1
       tempreg|=16000000/1000000U;
       pI2CHandle->pI2Cx->CR2= (tempreg & 0x3F);

	 //program the device own address in OAR1   addressing mode 7 or 10
	 tempreg=0;
	 tempreg|=pI2CHandle->I2C_Config_t.I2C_DeviceAddress<<1;  //1 to 7 bit for addressing mode 7
	 tempreg|= (1<<14);//must be set refer data sheet
	 pI2CHandle->pI2Cx->OAR1=tempreg;


	 //CCR Calculation and Configuration
	 //In Bit 15 for SM=0.FM=1
	 //Bit 14 IN FM Duty cycle ,0 means Tlow/Thigh=2
	                       //    1 means Tlow/Thigh=16/9
	 //0 to 11 bit used for CCR CALCULATION
	 uint16_t ccr_value=0;
	 tempreg=0;
//STANDARD MODE	 PCLK 100000
     if(pI2CHandle->I2C_Config_t.I2C_SCLSpeed <= I2C_SCL_SPEED_SM)
     {
    	 //IN SM  Tlow=Thigh
    	 //Tscl= 2 * CCR * Tpclk1
    	 //CCR = Fpclk1/( 2 * Fscl)
    	 //pI2CHandle->I2C_Config_t.I2C_SCLSpeed is the frequency of the serial clock given by user
    	 ccr_value=16000000/(2 * pI2CHandle->I2C_Config_t.I2C_SCLSpeed);
    	 tempreg |= (ccr_value & 0xFFF);
     }
     else
     {
       //mode is fast mode
    	  tempreg |= (1<<15);  //for FM Mode
    	  tempreg |= (pI2CHandle->I2C_Config_t.I2C_FMDutyCycle<<14);// 14 bit for FMDutyCycle
    	  if(pI2CHandle->I2C_Config_t.I2C_FMDutyCycle== I2C_FMDUTY_2)
    	  {
    		  ccr_value=16000000/(3 * pI2CHandle->I2C_Config_t.I2C_SCLSpeed);//for 0 In FM Mode Tlow/Thigh=2
    	  }
    	  else
    	  {
    		  ccr_value=16000000/(25 * pI2CHandle->I2C_Config_t.I2C_SCLSpeed);//for 1 In FM Mode Tlow/Thigh=16/9
    	  }
    	 tempreg |= (ccr_value & 0xFFF);
    	 pI2CHandle->pI2Cx->CCR = tempreg;
     }

}



void I2C_MainsendData(I2C_Handle *pI2CHandle,uint8_t *pTxBuffer,uint32_t Len,uint8_t SubNodeAddr,uint8_t Sr)
{
	//1. generate start condition

	pI2CHandle->pI2Cx->CR1 |= (1<<I2C_CR1_START);
	//2. check start condition attain
	while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_SB));

	//3. send 7 bit subnode address and  8th bit R/WR bit(total 8bits)

	I2C_ExecuteAddressPhase_Write(pI2CHandle->pI2Cx,SubNodeAddr);

	//4. check whether address phase complete by checking ADDR Flag in SR1
	   while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_ADDR));

	//5. CLEAR ADDR Flag according to software sequence
	   //Note: Until ADDR is cleared
	   I2C_ClearADDRFlag(pI2CHandle);

	//6. send data until Len becomes zero(all the data transmitted)

	   while(Len>0)
	   {
		   while(! I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_TXE)); //wait until TXE IS SET

		   pI2CHandle->pI2Cx->DR=pTxBuffer;

		   pTxBuffer++;
		   Len--;
	   }

	   while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_TXE)));
	   while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_BTF)));

	   //generate stop condition

	   pI2CHandle->pI2Cx->CR1 |= (1<<I2C_CR1_STOP);


}

