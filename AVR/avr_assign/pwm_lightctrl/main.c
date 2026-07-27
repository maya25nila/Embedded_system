#define F_CPU 16000000UL
# include<avr/io.h>
#include<util/delay.h>
volatile uint8_t count=0;
void dutycycle_step()
{
    count++;
    if(count==1)
    {
        OCR0A =64;
        _delay_ms(5);
    }
    else if(count==2)
    {
       
        OCR0A =128;
        _delay_ms(5);
    }

    else if(count==3)
    {
        OCR0A =192;
        _delay_ms(5);
    }
    else if(count==4)
    {
        OCR0A =0;
        _delay_ms(5);
        count=0;
    }
}

int main(void)
{
    DDRD |= (1<<DDD6); //CONFIGURE PD6 O/P
    DDRD &=~(1<<DDD2);//FOR push button i/p
    

   // configure pwm in FAST PWM IN NON-INVERTING MODE USING TIMER0
   TCCR0A |= (1<<COM0A1);
   TCCR0A &=~ (1<<COM0A0);
   TCCR0A |= ((1<<WGM01) | (1<<WGM00));
   //configure prescalar
   TCCR0B &=~(1<<CS00);
   TCCR0B &=~(1<<CS02);  
   TCCR0B |=(1<<CS01);
   TCNT0 =0;
   OCR0A=0;

    while(1)
    {
        while(!(PIND & (1<<PIND2)));
          _delay_ms(20);   
        dutycycle_step();
        

    }
}
