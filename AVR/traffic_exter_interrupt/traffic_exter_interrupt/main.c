/*
 * traffic_exter_interrupt.c
 *
 * Created: 12-12-2025 1
 * Created: 12-12-2025 11:44:14
 * Author : littles
 */
 #define F_CPU 16000000UL
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>

 void cw()
 {
 PORTB&=~((1<<PB1)|(1<<PB3));//YELLOW AND GREEN off
 PORTB|=(1<<PB2);//red on
 //motor ON
 PORTB|=(1<<PB5);
 PORTB&=~(1<<PB4);
 
 }
void stp(void)//for motor stop
{
	PORTB&=~((1<<PB5)|(1<<PB4));
}
 volatile int8_t motor_on=0;//set this for motor run
 ISR(INT0_vect)
 {                       //check green is on when interrupt come(switch press)
	 if(PORTB & (1<<PB1))
	 {
		motor_on=1;
	 }
	  
 }
 void red()
 {
 PORTB|=(1<<PB2);
 PORTB&=~((1<<PB1)|(1<<PB3));
 }
 void yellow()
 {
 PORTB|=(1<<PB3);
 PORTB&=~((1<<PB2)|(1<<PB1));
 }
 void green()
 {
 PORTB|=(1<<PB1);
 PORTB&=~((1<<PB2)|(1<<PB3));
 }

 int main(void)
 {
 DDRD&=~(1<<DDD2);//set as input pin for interrupt INT0 externally by switch
 PORTD&=~(1<<PD2);
 DDRB|=(1<<DDB2);//FOR RED
 DDRB|=(1<<DDB1);//FOR GREEN
 DDRB|=(1<<DDB3);//FOR YELLOW
 DDRB|=((1<<DDB4)|(1<<DDB5));// DC_MOTOR output pin
 sei();
 EIMSK|=(1<<INT0);//ENABLE INT0 interrupt
 EICRA|=((1<<ISC01)|(1<<ISC00));//interrupt in rising edge
 EIFR|=(1<<INTF0);//CLEARING the INTF0 FLAG
 while (1)
 {
 red();
 _delay_ms(4000);
 yellow();
 _delay_ms(4000);
 green();
 _delay_ms(4000);
 if(motor_on)
 {    
	  motor_on=0;//clear the motor_on
	 _delay_ms(3000);
	 cw();
	 _delay_ms(5000);
	 stp();
 }
 }

 }