

#include "timer0_fastpwm.h"
timer0_phasepwm_init()
{
    //PWM IN phase correct mode
   TCCR0A|=(1<<WGM00);
   TCCR0A&=~(1<<WGM01);
   
   //FOR pwm in non inverting
   TCCR0A|=(1<<COM0A1);
   TCCR0A&=~(1<<COM0A0);
   
   //for prescalar clk/8
   TCCR0B|=(1<<CS01);
   TCCR0B&=~(1<<CS00);
   TCCR0B&=~(1<<CS02);

}
uint16_t Brightness_ctrl(uint8_t bright)
{
uint16_t duty;
duty=(1024*bright)/100;
OCR0A =duty;
return duty;
}