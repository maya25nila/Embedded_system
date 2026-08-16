#ifndef TIMER0_PWM_H
#define TIMER0_PWM_H

#include <avr/io.h>

void timer0_phasepwm_init(void);
void Brightness_ctrl(uint8_t bright);

#endif