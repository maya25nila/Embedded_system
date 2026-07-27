#define F_CPU 16000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
volatile uint16_t count_TIMER1=0;
volatile uint16_t count_TIMER2=0;
ISR (TIMER1_COMPA_vect)
{
    if(count_TIMER1>=2499)//2500 count
   {   
        PORTB ^=(1<<PB1);
        count_TIMER1=0;
    }
    else
         count_TIMER1++;

}
ISR (TIMER2_COMPA_vect)
{
    if(count_TIMER2>=624)//625 count
    {
        PORTB ^=(1<<PB2);
        count_TIMER2=0;
    }
    
    else
         count_TIMER2++;

}
int main()
{
    DDRB |= (1<<DDB1);
    DDRB |= (1<<DDB2);
    sei();
    //TIMER1 CTC mode with  interrupt for 2 sec
    TCNT1=0;
    //for ctc mode
    TCCR1A &=~((1<<WGM11) | (1<<WGM10));
    TCCR1B |= (1<<WGM12);
    TCCR1B  &=~ (1<<WGM13);
    //FOR prescalar 64
    TCCR1B &=~ (1<<CS12);
    TCCR1B |= (1<<CS11) | (1<<CS10);
    //COMPARE VALUE
    OCR1A =199; //FOR 200 COUNT
    //for interrupt
    TIMSK1 |= (1<<OCIE1A);
    /*****TIMER2 CTC mode with  interrupt for 500ms 
    ***************/
    TCNT2=0;
    //for ctc mode
    TCCR2A &=~(1<<WGM20);
    TCCR2A |= (1<<WGM21);
    TCCR2B  &=~ (1<<WGM22);
    //FOR prescalar 64
    TCCR2B &=~ ((1<<CS20) | (1<<CS21));
    TCCR2B |= (1<<CS22);
    //COMPARE VALUE
    OCR2A =199; //FOR 200 COUNT
    //for interrupt
    TIMSK2 |= (1<<OCIE2A);
    
    while(1)
    {

    }
}