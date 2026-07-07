#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
    DDRB |=0X0F;//make 4 LSB bits of port B o/p pin
    DDRD &=~(1<<PD1);  //PD1 I/P PIN FOR push button
     PORTD |=(1<<PD1);//Enable pull up resistor

    PORTB &=0xF0;//set the initial state ,off all 4 led
    uint8_t i=0;
    while(1)
    {
        
     while((PIND & (1<<PD1)));//when button press  go to next step ie count
          PORTB =(PORTB & (0xF0) | (i & 0x0F));
        _delay_ms(20); //debounce dalay
         i++;
         if(i==16) //when count become 16 restart count
            i=0;
       while(!(PIND & (1<<PD1))) ;//when button released continue the loop for next button press    
        _delay_ms(20);//

    }
    return 0;
}