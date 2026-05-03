/****for  Toggle  on board LED****/

#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"
void delay(void)
{
	for(uint32_t i=0;i<500000;i++);
}


int main(void)
{
    GPIO_Handle Gpio_Led;
    Gpio_Led.pGPIOx=GPIOA;//To use user led2  in PA5 so select PORT A
    Gpio_Led.GPIO_PinConfig_t.GPIO_PinNumber=GPIO_PIN_NO_5;
    Gpio_Led.GPIO_PinConfig_t.GPIO_PinMode=GPIO_MODE_OUT;
    Gpio_Led.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_MEDIUM;
    Gpio_Led.GPIO_PinConfig_t.GPIO_PinOPTType=GPIO_OP_TYPE_PP;//push pull
    Gpio_Led.GPIO_PinConfig_t.GPIO_PinPuPd=GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOA,ENABLE);
    GPIO_Init(&Gpio_Led);

    //configure push button on board at PORT C (PC13)
        	GPIO_Handle Gpio_Pbutton;
        	Gpio_Pbutton.pGPIOx=GPIOC;
        	Gpio_Pbutton.GPIO_PinConfig_t.GPIO_PinNumber=GPIO_PIN_NO_13;
        	Gpio_Pbutton.GPIO_PinConfig_t.GPIO_PinMode=GPIO_MODE_IN;
        	Gpio_Pbutton.GPIO_PinConfig_t.GPIO_PinPuPd=GPIO_NO_PUPD;
        	Gpio_Pbutton.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_MEDIUM;

        	GPIO_PeriClockControl(GPIOC,ENABLE);
        	    GPIO_Init(&Gpio_Pbutton);
    while(1)
    {
    	//GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
    	//delay();

    //for turn on led  when push button B1 pressed
       if(GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13) == 0)//PC13 active low
      {
    	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,1);
    	delay();

      }
    else
    	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,0);
    }

}
