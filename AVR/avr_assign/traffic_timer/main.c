#define F_CPU 16000000UL
#include<avr/io.h>
void delay_1sec(uint8_t time)
{
  while(time--)
  {
  for(uint8_t i=0;i<78;i++)
    {
    while(!(TIFR0 & (1<<OCF0A)));//chk whether flag set
    TIFR0 |=(1 << OCF0A);//Clear the flag by writing 1

    }
  }
}
void red(void)
{
  PORTB |=(1<<PB3);
  PORTB &=~((1<<PB1) | (1<<PB2));

}
void green(void)
{
  PORTB |= (1<<PB1);
  PORTB &=~ ((1<<PB2) | (1<<PB3));
}
void orange(void)
{
  PORTB |= (1<<PB2);
  PORTB &=~ ((1<<PB1) | (1<<PB3));
}


int main(void)
{
    DDRB |=(1<<DDB1);//output pin for green led
    DDRB |=(1<<DDB2);//output pin for orange led
    DDRB |=(1<<DDB3);//output pin for red led
//1s delay using Timer0 ctc mode prescalar 1024,ie 78 times in loop
    //Timer0 initialization
    TCNT0=0; //set the initial value
    TCCR0A &=~(1<<WGM00);
    TCCR0A |=(1<<WGM01);//ctc mode
    //To set prescalar 1024
    TCCR0B |=((1<<CS02) | (1<<CS00));
    TCCR0B &=~(1<<CS01);
    
    OCR0A =199;//set point 199 hex value c7
    while(1)
    {
    green();
    delay_1sec(10);
    orange();
    delay_1sec(3);
    red();
    delay_1sec(10);
    }
    
}