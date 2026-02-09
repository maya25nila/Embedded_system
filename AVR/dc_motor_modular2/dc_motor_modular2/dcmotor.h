/*
 * dcmotor.h
 *
 * Created: 08-12-2025 09:28:17
 *  Author: littles
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include <avr/io.h>

void pwm_init(void);
void cw_motor(uint8_t);
void stop(void);



#endif /* DCMOTOR_H_ */