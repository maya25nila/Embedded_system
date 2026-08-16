#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<stdlib.h>
#include "uart.h"
#include "timer0_pwm.h"
int main(void)
{
  char buffer[20];
  uint8_t brightness;
  DDRD |= (1<<DDD6); // Set PD6 as output for PWM led connected
  uart_TxRx_init();
  timer0_phasepwm_init();

  uart_string_tx("LED Light Control");
  uart_string_tx("\n");
  uart_string_tx("on : on");
  uart_string_tx("\n");
  uart_string_tx("off : off");
  uart_string_tx("\n");
  uart_string_tx("Brightness 0-100");
  uart_string_tx("\n");
 
    while (1) 
    {
		  uart_string_tx("Enter command");
      uart_string_tx("\n");
      uart_string_rx(buffer, sizeof(buffer));
      if (strcmp(buffer, "on") == 0)
      {
        Brightness_ctrl(100); // Set duty cycle to 100% for full brightness
        uart_string_tx("LED turned on");
        uart_string_tx("\n");
        uart_string_tx("Enter percentage(0-100) to control brightness");
        uart_string_tx("\n");
        uart_string_rx(buffer, sizeof(buffer));
        brightness = atoi(buffer); // Convert string to integer
         if (brightness <= 100) {
           Brightness_ctrl(brightness);
            uart_string_tx("Brightness set to ");
            uart_string_tx(buffer);
            uart_string_tx("%");
            uart_string_tx("\n");
            

          
        }
      }
          else if (strcmp(buffer, "off") == 0)
           {
              Brightness_ctrl(0); // Set duty cycle to 0% for turning off the LED
             uart_string_tx("LED turned off");

             uart_string_tx("\n");
           }
         else
            {
             uart_string_tx("Invalid command");
             uart_string_tx("\n");
            }

    }
  }
