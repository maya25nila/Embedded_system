/*
 * exam_pwm.c
 *
 * Created: 30-11-2025 15:19:54
 * Author : littles
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD|=(1<<DDD6);
	
	//configure for phase correct pwm
  TCCR0A|=(1<<WGM00);
  TCCR0A&=~(1<<WGM01);
  //configure for non-inverting pwm
  TCCR0A|=(1<<COM0A1);
  TCCR0A&=~(1<<COM0A0);
  //configure for prescalar=8
  TCCR0B&=~(1<<CS02);
  TCCR0B&=~(1<<CS00);
  TCCR0B|=(1<<CS01);
  OCR0A=128;
    while (1)
    {
		for(int i=0;i<=255;i++){
			OCR0A=i;
			 _delay_ms(5);
    }
	for(int i=255;i>=0;i--){
		OCR0A=i;
		 _delay_ms(5);
	}
	
   }
}








    
    


