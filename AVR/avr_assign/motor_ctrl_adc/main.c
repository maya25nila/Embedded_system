
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
void adc_init(void)
{
	//configure ADMUX Register
	//Set the reference voltage as  AVcc 
	ADMUX|=(1<<REFS0);
	ADMUX&=~(1<<REFS1);
	//configure for right adjust the data
	ADMUX&=~(1<<ADLAR);
	//Configure for channel 0(ADC0)
	ADMUX&=~((1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0));
	//Configure ADCSRA
	ADCSRA|=(1<<ADEN);//SET ADC Enable bit
	
	//SET pre scalar 64 , we can read ADC value in 200-250khz
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1);
	ADCSRA&=~(1<<ADPS0);
	//configure DIDR0 register
	DIDR0|=(1<<ADC0D);//FOR disable corresponding digital i/p buffer and read analog signal from ADC0
	ADCSRA|=(1<<ADSC);//ADC start convertion bit to start first conversion
}
uint16_t adc_read(void)
{
	volatile uint16_t value;
    while(ADCSRA & (1<<ADSC));
		
			value = (uint16_t)ADCL | ((uint16_t)ADCH << 8);
			ADCSRA |= (1<<ADSC);//to start next conversion
			return value;
		
}
void timer0_fastpwm_init(void)
    
  {  
    //for fast PWM
    
	TCCR0A|=(1<<WGM00);
    TCCR0A|=(1<<WGM01);
    
    //FOR pwm in  nonverting
    TCCR0A|=(1<<COM0A1);
    TCCR0A&=~(1<<COM0A0);
    
    //for prescalar clk/8
    TCCR0B|=(1<<CS01);
    TCCR0B&=~(1<<CS00);
    TCCR0B&=~(1<<CS02);
  }
 void motor_speed(uint16_t adc_value)
 {
	uint8_t pwm_value;
	pwm_value=(adc_value * 255UL)/1023;//convert 10 bit adc value to 8 bit value
	OCR0A=pwm_value;
 }
int main(void)
{
DDRD|=(1<<DDD6);//PWM-OC0A output in PD6 so configure PD6 as output pin

DDRD |= (1<<DDD7);//configure PD7 as output pin for MOTOR DIRECTION
PORTD|=(1<<PD7);//set PD7 as high for forward direction

    adc_init();
	timer0_fastpwm_init();
    while(1)
    {
		uint16_t adc_val;
		adc_val=adc_read();
		motor_speed(adc_val);
    }
    return 0;
}

