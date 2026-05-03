/*
 * Gpioint.c
 *
 *  Created on: Mar 2, 2026
 *      Author: nilaNila
 */

#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"

void delay1()
{
 for(uint8_t i=0;i<=500000;i++);

}
int main1(void)
{
	GPIO_Handle GpioLed,GpioIntr;
	GpioLed.pGPIOx=GPIOA;
	GpioLed.GPIO_PinConfig_t.GPIO_PinNumber=GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig_t.GPIO_PinMode=GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig_t.GPIO_PinOPTType=GPIO_OP_TYPE_PP;//for 1 led on for 0 off
	GpioLed.GPIO_PinConfig_t.GPIO_PinPuPd=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);

	GpioIntr.pGPIOx=GPIOC;
	GpioIntr.GPIO_PinConfig_t.GPIO_PinNumber=GPIO_PIN_NO_13;//on board push button at portc pin no:13
	GpioIntr.GPIO_PinConfig_t.GPIO_PinMode=GPIO_MODE_INT_FT;//SINCE on board push button active low
	GpioIntr.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GpioIntr.GPIO_PinConfig_t.GPIO_PinPuPd=GPIO_PIN_PU;//button active low

	GPIO_PeriClockControl(GPIOC,ENABLE);
	GPIO_Init(&GpioIntr);

	GPIO_IRQInterruptConfig(IRQ_NO_EXTI10_15,ENABLE);

	while(1);
}
	void EXTI15_10_IRQHandler(void)
	{
		GPIO_IRQHandling(GPIO_PIN_NO_13);
		GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
	}


