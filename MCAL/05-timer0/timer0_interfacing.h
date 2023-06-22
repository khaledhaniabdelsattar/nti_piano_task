/*
 * timer0_interfacing.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Khaled
 */

#ifndef TIMER0_INTERFACING_H_
#define TIMER0_INTERFACING_H_
#include "bitmath.h"
#include "std_types.h"
#include "timer0_registers.h"
#include "timer0_names.h"

void enable_time0_interrupt();
void disable_time0_interrupt();
void enable_time0_CTC_interrupt();
void disable_time0_CTC_interrupt();
void select_timer0_mode(timer0_modes mode);
void start_timer0(timer0_prescalers prescaler);
void timer0_preload(u8 preload);
void timer_0_write_on_ctc_reg(u8 preload);
void stop_timer0();
void select_output_pwm_mode(pwm_mode wave);
 ;




#endif /* TIMER0_INTERFACING_H_ */
