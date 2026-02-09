/*
 * adc.c
 *
 * Created: 26-12-2025 11:41:18
 * Author : littles
 reads adc value to a variable
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void adc_init(void)
{
	//configure ADMUX Register
	//Set the refference voltage as  AVcc 
	ADMUX|=(1<<REFS0);
	ADMUX&=~(1<<REFS1);
	//configure for right adjust the data
	ADMUX&=~(1<<ADLAR);
	//Configure for channel 0(ADC0)
	ADMUX&=~((1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0));
	//Configure ADCSRA
	ADCSRA|=(1<<ADEN);//SET ADC Enable bit
	ADCSRA|=(1<<ADSC);//ADC start convertion bit
		//SET pre scalar 64 , we can read ADC value in 200-250khz
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1);
	ADCSRA&=~(1<<ADPS0);
	//configure DIDR0 register
	DIDR0|=(1<<ADC0D);//FOR disable corresponding digital i/p buffer and read analog signal from ADC0
}



int main(void)
{
   uint16_t value;   
   adc_init(); 
    while (1) 
    {
		while(ADCSRA & (1<<ADSC));
		
			value=ADCL|(ADCH<<8);
			
			ADCSRA |= (1<<ADSC);//to start next conversion
		
    }
}
/*for left shift data
ADMUX|=(1<<ADLAR);
//Reading from ADC register
value=ADCH|(ADCL>>8);
*/

