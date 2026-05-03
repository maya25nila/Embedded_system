/*
 * stm32f401xx_gpio_driver.c
 *
 *  Created on: Feb 20, 2026
 *      Author: nilaNila
 */

#include<stdint.h>
#include "stm32f401xx_gpio_driver.h"

/*********************************************************************
 * @fn          - GPIO_PeriClockControl
 *
 * @brief       - Enables or disables peripheral clock for GPIO port
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - EnorDi: ENABLE or DISABLE macros
 *
 * @return      - none
 *
 * @Note        - refer CLOCK ENABLE or DISABLE Macros
 *********************************************************************/

void GPIO_PeriClockControl(GPIO_RegDef *pGPIOx,uint8_t EnorDi) //arguments -port and clk enable or disable
{
	if(EnorDi==ENABLE)
	{
		if(pGPIOx==GPIOA)
		{
			GPIOA_CLK_EN();
		}
		else if(pGPIOx==GPIOB)
		{
			GPIOB_CLK_EN();
		}
		else if(pGPIOx==GPIOC)
				{
					GPIOC_CLK_EN();
				}
		else if(pGPIOx==GPIOD)
				{
					GPIOD_CLK_EN();
				}
		else if(pGPIOx==GPIOE)
				{
					GPIOE_CLK_EN();
				}
		else if(pGPIOx==GPIOH)
				{
					GPIOH_CLK_EN();
				}

	}
	//for DISABLE CLOCK
	else
	   {
		if(pGPIOx==GPIOA)

	     {
		  GPIOA_CLK_DIS();
	     }
	  else if(pGPIOx == GPIOB)
	     {
		    GPIOB_CLK_DIS();
	      }
	  else if(pGPIOx == GPIOC)
			{
				GPIOC_CLK_DIS();
			}
	  else if(pGPIOx == GPIOD)
			{
				GPIOD_CLK_DIS();
			}
	  else if(pGPIOx == GPIOE)
			{
				GPIOE_CLK_DIS();
			}
	   else if(pGPIOx == GPIOH)
			{
				GPIOH_CLK_DIS();
			}
	   }
}

/*********************************************************************
 * @fn          - GPIO_Init
 *
 * @brief       - This function is used to read value from GPIO Pin
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   - GPIO Pin Number
 *
 * @return      - uint8_t (value inside that pin)
 *
 * @Note        - refer gpio Pin macros
 *********************************************************************/
void GPIO_Init(GPIO_Handle *pGPIOHandle)
{


	    uint32_t temp=0;
	 //Handle the Peripheral clock
	 	GPIO_PeriClockControl(pGPIOHandle->pGPIOx,ENABLE);

	 //Configure GPIO Pin MODES
	 if(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode<=GPIO_MODE_ANALOG)//check value below or equal to 3 for mode selection
	 {
	 temp=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode<<(2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber));//create mask temp
	 pGPIOHandle->pGPIOx->MODER &=~(0x3<<2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);//clear the register value in corresponding pin positions
	 pGPIOHandle->pGPIOx->MODER|=temp;//set the value of register
	 temp=0;
	 }
	 else
	 {
	 //for interrupt
		 //for falling Trigger
	 if(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode==GPIO_MODE_INT_FT){

      EXTI->FTSR |=(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);

      EXTI->RTSR &=~(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);

	     }
	 //for rising trigger
	 else if(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode==GPIO_MODE_INT_RT){

	      EXTI->RTSR|=(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);

	      EXTI->FTSR &=~(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);
	     }
	 //for falling and rising trigger
	 else if(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode==GPIO_MODE_INT_RFT){

	      EXTI->FTSR|=(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);

	      EXTI->RTSR|=(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);
	     }

	 //configure GPIO Port with SYSCONFIG-EXTICR Register

	 uint8_t temp1=pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber/4;//To select EXTICR Register(EXTICR1,2,3,4),we get array index
	 uint8_t temp2=pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber % 4;//to select pin number
	 uint8_t portcode =GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
	 SYSCFG_CLK_EN();
	 SYSCFG->EXTICR[temp1]|=portcode<<(4*temp2);

	 //Enable EXTI Interrupt delivery by IMR Register
	 EXTI->IMR|=(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);

	 }

	 //Configure GPIO Pin SPEED

	 temp=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinSpeed<<(2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber));
	 pGPIOHandle->pGPIOx->OSPEEDR &=~(0x3<<2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);//clear the register position
	 pGPIOHandle->pGPIOx->OSPEEDR|=temp;
	 temp=0;

	 //Configure PUPD Setting

	 temp=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinPuPd<<(2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber));
	 pGPIOHandle->pGPIOx->PUPDR &=~(0x3<<2*pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);
	 pGPIOHandle->pGPIOx->PUPDR|=temp;
	 temp=0;

	 //Configure OutPut Type

	 temp=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinOPTType<<(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber));//ONE Bit configuration
	 pGPIOHandle->pGPIOx->OTYPER &=~(1<<pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber);//clear the corresponding bit
	 pGPIOHandle->pGPIOx->OTYPER|=temp;
	 temp=0;

	 //Configure Alternate Function AFL,AFH
	 if(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode==GPIO_MODE_ALTFN )
	 {
	 	uint8_t temp1,temp2,temp3;
	 	temp1=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber) / 8;//To choose AFL/AFH(0 FOR AFL AND 1 FOR AFH
	 	temp2=(pGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber) % 8;//To choose pin number position 0-7 for both AFL and AFH(AFH FROM 8 TO 15)
	 	pGPIOHandle->pGPIOx->AFR[temp1] &=~((0xF)<< (4*temp2));//selecting AFL/AFH  and clear 4 bit ,(temp2 value from 0-7) each pin configured with 4 bits
	 	temp3=pGPIOHandle->GPIO_PinConfig_t.GPIO_PinAltFun<<(4*temp2);
	 	pGPIOHandle->pGPIOx->AFR[temp1] |=temp3;
	 }

}

/*********************************************************************
 * @fn          - GPIO_DeInit
 *
 * @brief       - This function is used to Deinitialize GPIO Pins
 *
 * @param[in]   - pGPIOHandle:pointer to GPIOHandle structure
 * @param[in]   -
 * @return      -none
 *
 * @Note        -refer macros for GPIO configuration
 *********************************************************************/


void GPIO_DeInit(GPIO_RegDef *pGPIOx)
{

    if(pGPIOx == GPIOA)
    {
    	GPIOA_CLK_RST();  // Reset GPIOA
        //RCC->AHB1RSTR &= ~(1 << 0); // Release reset
    }
    else if(pGPIOx == GPIOB)
    {
    	GPIOB_CLK_RST();  // Reset GPIOB
       // RCC->AHB1RSTR &= ~(1 << 1);
    }
    else if(pGPIOx == GPIOC)
       {
    	GPIOC_CLK_RST();  // Reset GPIOC
        //RCC->AHB1RSTR &= ~(1 << 2);
       }
    else if(pGPIOx == GPIOD)
       {
    	GPIOD_CLK_RST();  // Reset GPIOD
       // RCC->AHB1RSTR &= ~(1 << 3);
       }
    else if(pGPIOx == GPIOE)
       {
    	GPIOE_CLK_RST();  // Reset GPIOE
       // RCC->AHB1RSTR &= ~(1 << 4);
       }
    else if(pGPIOx == GPIOH)
       {
    	GPIOH_CLK_RST();  // Reset GPIOH
        //RCC->AHB1RSTR &= ~(1 << 7);
       }
}
/*********************************************************************
 * @fn          - GPIO_ReadFromInputPin
 *
 * @brief       - This function is used to read value from GPIO Pin
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   - GPIO Pin Number
 *
 * @return      - uint8_t (value inside that pin)
 *
 * @Note        - refer gpio Pin macros
 *********************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR>>PinNumber) & 00000001);//IDR REGISTER right shift to PinNumber times then AND with 1

	return value;
}
/*********************************************************************
 * @fn          -  GPIO_ReadFromInputPort
 *
 * @brief       - This function is used to read value from GPIO port
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   -
 *
 * @return      - uint16_t (value inside that port)
 *
 * @Note        - refer gpio Pin macros
 *********************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef *pGPIOx)
{
	uint16_t value;      //16 pins for each port (16 bit data)
	value = (uint16_t)pGPIOx->IDR;  //IDR 32 Bit Register
	return value;
}
/*********************************************************************
 * @fn          -  GPIO_WriteToOutputPin
 *
 * @brief       - This function is used to write value to GPIO pin
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   -PinNumber
 * @param[in]   -value
 *
 * @return      -
 *
 * @Note        -
 *********************************************************************/

void GPIO_WriteToOutputPin(GPIO_RegDef *pGPIOx,uint8_t PinNumber,uint16_t value)
{
	if(value==1)
	{

	pGPIOx->ODR |= (1<<PinNumber); //write 1
	}
	else
	{
		pGPIOx->ODR &= ~(1<<PinNumber);//write 0
	}
}
/*********************************************************************
 * @fn          -  GPIO_WriteToOutputPort
 *
 * @brief       - This function is used to write value to GPIO port
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   -PinNumber
 * @param[in]   -value
 *
 * @return      -
 *
 * @Note        -
 *********************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef *pGPIOx,uint16_t value)
{
	pGPIOx->ODR= (uint32_t)value;
}

/*********************************************************************
 * @fn          - GPIO_ToggleOutputPin
 *
 * @brief       - This function is used to write value to GPIO port
 *
 * @param[in]   - pGPI0x: pointer to GPIORegDef structure
 * @param[in]   -PinNumber
 * @param[in]   -
 *
 * @return      -
 *
 * @Note        -
 *********************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}


/*********************************************************************
 * @fn          - GPIO_IRQInterruptConfig
 *
 * @brief       - This function is used for INterrupt ENABLE/DISABLE
 *
 * @param[in]   - IRQNumber
 * @param[in]   -EnorDi
 *
 * @return      -
 *
 * @Note        -
 *********************************************************************/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
		{
		  if(IRQNumber<32)
		  {
            *NVIC_ISER0 |= (1<<IRQNumber);

		  }
		else if((IRQNumber>31) && IRQNumber<64)
		{
			*NVIC_ISER1|=(1<<IRQNumber%32);
         }
		else if(IRQNumber>63 && IRQNumber<96)
		{
			*NVIC_ISER2|=(1<<IRQNumber%64);
		}
		}
		else     //for clear the interrupt
			{
			if(IRQNumber<32)
					  {
			            *NVIC_ICER0 |= (1<<IRQNumber);

					  }
					else if((IRQNumber>31) && IRQNumber<64)
					{
						*NVIC_ICER1 |= (1<<IRQNumber%32);
			         }
					else if(IRQNumber>63 && IRQNumber<96)
					{
						*NVIC_ICER2 |= (1<<IRQNumber%64);
					}
		    }
}
void GPIO_IRQHandling(uint8_t PinNumber)
{
	//clear the EXTI PR Register corresponding to PinNumber
	if(EXTI->PR & (1<<PinNumber))
	  EXTI->PR|=(1<<PinNumber);
}
