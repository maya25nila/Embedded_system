#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

int main(void)
{
    // PB1, PB2, PB3 as outputs
    DDRB |= (1 << DDB1) | (1 << DDB2) | (1 << DDB3);

    // Turn everything OFF initially
    PORTB &= ~((1 << PB1) | (1 << PB2) | (1 << PB3));

    // GREEN only
    PORTB |= (1 << PB1);

    while (1)
    {
    }
}