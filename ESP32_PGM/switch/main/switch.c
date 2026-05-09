#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"  //for delay
#include "freertos/task.h"     //for delay

#define LED_GPIO 2
#define SWITCH_GPIO 5
 
void app_main(void)
{
    gpio_reset_pin(LED_GPIO);//rest the pin 2 
 gpio_set_direction(LED_GPIO,GPIO_MODE_OUTPUT);//set pin direction as output

gpio_reset_pin(SWITCH_GPIO);//rest the pin 5
 gpio_set_direction(SWITCH_GPIO,GPIO_MODE_INPUT);//set pin direction as input
 gpio_pullup_en(SWITCH_GPIO);
 while(1)
 {
   if(!(gpio_get_level(SWITCH_GPIO)))
      gpio_set_level(LED_GPIO,1);//switch pressed LED ON
    else
    gpio_set_level(LED_GPIO,0);//turning LED off

}
}
