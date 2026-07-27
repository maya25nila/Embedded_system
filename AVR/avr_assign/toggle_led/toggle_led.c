#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
    DDRD |= (1<<DDD5); //SET PD5 as output pin

    while(1)
    {
        PORTD |=(1<<PD5);
        _delay_ms(3000);
        PORTD &=~(1<<PD5);
        _delay_ms(5000);

    }


}