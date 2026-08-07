# define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
volatile uint16_t adc_value=0;
void Timer1_phasecrt_pwmInit()
{
  //compare o/p mode with phase correct pwm
 TCCR1A|= (1<<COM1A1);
 TCCR1A&= ~(1<<COM1A0);
//timer 1 with pwm with phase correct mode top value in ICR1 TO GET O/P
//in OC1A PIN (PORTB Pin1)
 TCCR1A&= ~(1<<WGM10);
TCCR1A |=(1<<WGM11);
TCCR1B &= ~(1<<WGM12);
TCCR1B |=(1<<WGM13);
//PRESCALAR 8 for 50hz pwm frequency
TCCR1B &= ~(1<<CS10);
TCCR1B |=(1<<CS11);
TCCR1B &=~(1<<CS12);
//LOAD INITIAL VALUE for counter
TCNT1 =0;
//define top value
ICR1= 20000;  //16 bit register,
OCR1A= 3000;//SERVO INITIAL POSITION AT 90 DEGREE
}
void adc_Init()
    {
      ADMUX |= (1<<REFS0);//select reference voltage Avcc
      ADMUX &=~(1<<REFS1);
      //Right Adjust
      ADMUX &=~(1<<ADLAR);
      //select ADC Channnel 0
      ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));
      //ENABLE ADC
      ADCSRA |=(1<<ADEN);//adc enable bit
      //SELECT 64 CLK FREQUENCY to read ADC value
      ADCSRA |= ((1<<ADPS2) | (1<<ADPS1));
      ADCSRA &=~(1<<ADPS0);
      ADCSRA |= (1<<ADSC);//adc start convertion 

    }
    void ADC_Read()
    {
      
      while(ADCSRA & (1<<ADSC));//ADSC BIT 0 AFTER one convertion complete
      adc_value=ADC;//adc ranges 0 to 1023
      ADCSRA |= (1<<ADSC);//To start next convertion
    }
void servo_mtr_ctrl()
{
  OCR1A =2000+((uint32_t)adc_value*2000)/1023;//multiplied value come in 32 bit range
  
}

int main()
{
  DDRC &= ~(1<<PC0);//SET PC0 input pin for ADC0 CHANNEL from potentiometer
  DDRB |=(1<<PB1);//SET PB1 as o/p pin for servo motor
    Timer1_phasecrt_pwmInit();
    adc_Init();

 while(1)
 {
    ADC_Read();
    servo_mtr_ctrl();
    _delay_ms(10);
 }

}