#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

volatile uint16_t adc_value;
volatile uint8_t temperature;
void adc_init()
{
    //select the reference vge avcc
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);
    //for left adjust
    ADMUX |= (1<<ADLAR);
    //FOR CHANNEL 0
    ADMUX &= ~((1<<MUX0) |(1<<MUX1) | (1<<MUX2) | (1<<MUX3));
    ADCSRA |= (1<<ADEN); //ADC Enable
   
    //prescalar 128
    ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
    
}
uint8_t adc_read()
{
   ADCSRA  |=(1<<ADSC); //ADC Start convertion bit
 while(ADCSRA & (1<<ADSC));//ADSC BECOME 0 when convertion complete
  adc_value=((ADCL>>6)|(ADCH<<2));
  
  temperature=(adc_value *500UL)/1024;
  return(temperature);

}
void timer0_fastpwm_init()
{
 // configure pwm in FAST PWM IN NON-INVERTING MODE USING TIMER0
   TCCR0A |= (1<<COM0A1);
   TCCR0A &=~ (1<<COM0A0);
   TCCR0A |= ((1<<WGM01) | (1<<WGM00));
   //configure prescalar
   TCCR0B &=~(1<<CS00);
   TCCR0B &=~(1<<CS02);  
   TCCR0B |=(1<<CS01);
   TCNT0 =0;
   OCR0A=0;
}
void motor_ctrl()
{
    if(temperature<=25)
    {
      OCR0A=0;
      
    }
    else if(temperature<=28 )
      {
        OCR0A=128;
        
      }
      else if(temperature<=30)
      {
         OCR0A=192;
         
      }
      else if(temperature>30) 
      {
         OCR0A=255;
         
      }
}
int main(void)
{
    uint8_t System_ON=0;  
    DDRB &= ~(1<<DDB1);//for push button to make the system ON or OFF
    DDRD |= (1<<DDD6);//PWM O/P at PD6 to drive motor
    timer0_fastpwm_init();
    adc_init();
    
    while(1)
    {
    
    while(!(PINB & (1<<PINB1)));
    _delay_ms(20);
      System_ON^=1;
      if(System_ON)
      {
        temperature=adc_read();
         motor_ctrl();

      }
      else
      {
        OCR0A= 0;
      }
    }
return 0;
}