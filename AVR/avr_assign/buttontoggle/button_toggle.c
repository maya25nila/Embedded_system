#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
    DDRB |= (1<<DDB3);  //B3 AS O/P PIN FOR RED LED
    DDRB |= (1<<DDB2);   //B2 AS O/P PIN FOR GREEN LED
    DDRB &=~(1<<DDB0);  //B6 AS I/P PIN FOR PUSH BUTTON
    PORTB |=(1<<PB0);  //Enable pull up resistor

    //set the initial condition
    
    
        PORTB |= (1<<PB3); //RED ON
        PORTB  &= ~(1<<PB2); //GREEN OFF
        _delay_ms(1000);
    
    while(1)
    {
        
        if(!(PINB &(1<<PB0))) 
        { 
        
           PORTB ^= (1 << PB3);
           PORTB ^= (1 << PB2);
            
            while (!(PINB & (1 << PB0)));  // wait for release

            _delay_ms(50);//debounce delay
        }
        
    }
}