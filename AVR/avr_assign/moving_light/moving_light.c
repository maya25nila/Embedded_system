#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
DDRB =0xFF;//set all pin as output

PORTB =0x00;//Initial condition Turn off all LEDS
while(1)
{
    for(uint8_t i=0;i<6;i++)
    {
      PORTB =(1<<i);
      _delay_ms(1000);
    }

}
return 0;
}