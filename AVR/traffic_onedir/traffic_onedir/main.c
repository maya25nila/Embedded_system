/*
 * traffic_onedir.c
 *
 * Created: 20-11-2025 12:03:37
 * Author : littles
 Objective: Write a program to simulate a basic one-way traffic light controller 
 using three LEDs to represent the Green, Orange, and Red signals without using 
 inbuilt _delay() function.
Requirements: The system must control three LEDs connected to any three available 
GPIO pins on PORTB. Upon system start, the Green LED must turn ON for a duration of 
10 seconds. After this period, the Green LED must turn OFF and the Orange LED must t
urn ON for 3 seconds. Once the Orange duration ends, it must turn OFF and the Red LED 
must turn ON for 10 seconds. The program must be designed to continuously cycle through 
this Green-Orange-Red sequence indefinitely.


 */ 
 #define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

void timer0_init(void)
{
    // Start timer from 0
    TCNT0 = 0;

    // Compare value for 1 ms
    OCR0A = 249;

    // CTC mode
    TCCR0A = (1 << WGM01);

    // Prescaler = 64
    TCCR0B = (1 << CS01) | (1 << CS00);

    // Clear compare match flag
    TIFR0 = (1 << OCF0A);
}

void delay_ms(uint16_t ms)
{
    while (ms--)
    {
        // Wait for compare match
        while (!(TIFR0 & (1 << OCF0A)))
        {
        }

        // Clear compare match flag
        TIFR0 = (1 << OCF0A);
    }
}

void green_Light(){
	PORTB |=(1<<PORTB3); //set PB3=1 for green
	PORTB &=~(1<<PORTB2);//PB2 =0 for yellow
	PORTB &=~(1<<PORTB1);//PB1=0 for red
}
void yellow_Light(){
	PORTB |=(1<<PORTB2); //set PB1=1 for yellow
	PORTB &=~(1<<PORTB1);//PB2 =0as red
	PORTB &=~(1<<PORTB3);//PB3=0 as green
}
void red_Light(){
	PORTB |=(1<<PORTB1); //set PB1=1 for red
	PORTB &=~(1<<PORTB2);//PB2 =0as yellow
	PORTB &=~(1<<PORTB3);//PB3=0 as green
}

int main(void)
{
   DDRB|=(1<<DDB1)|(1<<DDB2)|(1<<DDB3);//SET PB1=PB2=PB3=1 as output pin
   timer0_init();
    while (1) 
    {
		
		green_Light();
		delay_ms(10000);
		yellow_Light();
		delay_ms(3000);
		red_Light();
		delay_ms(10000);
    }
}

