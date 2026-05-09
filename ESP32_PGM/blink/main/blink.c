#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_GPIO 2
void app_main(void)
{ 
    gpio_reset_pin(LED_GPIO);//rest the pin 2
    gpio_set_direction(LED_GPIO,GPIO_MODE_OUTPUT);//set pin direction as output
    while(1)
    {
        gpio_set_level(LED_GPIO,1);//turning LED ON
        vTaskDelay(1000/portTICK_PERIOD_MS);//delay of 1 sec
        gpio_set_level(LED_GPIO,0);//turning LED OFF
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    

}
