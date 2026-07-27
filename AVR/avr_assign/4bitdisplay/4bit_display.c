#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void display_count(uint8_t i)
{
 PORTB =(PORTB & (0xF0) | (i & 0x0F));
}
int main(void)
{
    DDRB |=0X0F;//make 4 LSB bits of port B o/p pin
    DDRD &=~(1<<DDD2);  //PD2 I/P PIN FOR push button
    PORTD |=(1<<PD2);//Enable pull up resistor

    PORTB &=0xF0;//set the initial state ,off all 4 led
    uint8_t i=0;
    display_count(i);//display  initial value
    
    while(1)
    {
        
     while((PIND & (1<<PIND2)));//when button press  go to next step ie count
        _delay_ms(20); //debounce dalay
         i++;
         
          if(i==16) //when count become 16 clear  count value
          {
            i=0;
          }
      display_count(i);
       while(!(PIND & (1<<PIND2))) ;//when button released continue the loop for checking next button press    
        _delay_ms(20);//

    }
    return 0;
}