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
    while(1)
    {
        
        if(!(PINB &(1<<PB0)))  //check for button press
        {
            PORTB ^=(1<<PB3);
            PORTB ^=(1<<PB2);
            _delay_ms(500);
        }
    }
}