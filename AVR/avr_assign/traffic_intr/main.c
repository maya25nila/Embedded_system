# define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

volatile uint8_t flag_button=0;
 ISR(INT0_vect)
 {                    
	 
		flag_button=1;//when interrupt come set flag bit
	  
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
void emergency_green()
{
 if(flag_button)
       {
        green();
        _delay_ms(2000);
        flag_button=0;
        
       }
}
int main(void)
{
    sei();
    
    //for external interrupt INT0
    EIMSK|=(1<<INT0);//ENABLE INT0 interrupt
    EICRA|=((1<<ISC01)|(1<<ISC00));//interrupt in rising edge
    EIFR|=(1<<INTF0);//CLEARING the INTF0 FLAG
    //MAKE 3 PINS OF PORTB as o/p for red green orange light
    DDRB |=((1<<DDB1) | (1<<DDB2) | (1<<DDB3));
    DDRD&=~(1<<DDD2);//set as input pin for interrupt INT0 externally by button
    PORTD&=~(1<<PD2);
    

    while(1)
    {
      red();
      _delay_ms(10000);
      emergency_green();
      orange();
      _delay_ms(3000);
      emergency_green();
      green();
      _delay_ms(10000);
      emergency_green();
    }
}