# define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<stdint.h>
#include "lcd.h"
uint8_t button_time()
{
    uint16_t time=0;
     while(PINB & (1<<PINB1))
     {
           _delay_ms(10);//debounce time
            time++;
            if(time >=200)//for more than 2s press(10ms *200)
              {
                return 1; //count reset to 000000000
              }
      }
      return 0;  //count increment by 1
              
     
}

int main(void)
{
    uint32_t count=0;
    DDRB &= ~(1<<DDB1);
    lcd_init();
	  lcd_set_cursor(0, 0);
	  lcd_print("9 digit count");
    lcd_set_cursor(1, 0);
    display_9digit(count);//initial print 0

    while(1)
    {
      if(PINB &(1<<PINB1))
      {
        if(button_time())
        {
          count=0;
         
        }
        else
        {
          count++;
        
        }
        lcd_set_cursor(1, 0);
          display_9digit(count);
        while(PINB & (1<<PINB1));

      }
    }
    return 0;
}