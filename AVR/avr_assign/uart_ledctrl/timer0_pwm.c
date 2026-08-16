

#include "timer0_pwm.h"
void timer0_phasepwm_init()
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
void Brightness_ctrl(uint8_t bright)
{

OCR0A =(255*bright)/100;//set duty cycle

}