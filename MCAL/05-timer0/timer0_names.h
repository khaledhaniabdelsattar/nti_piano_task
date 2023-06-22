/*
 * timer0_names.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Khaled
 */

#ifndef TIMER0_NAMES_H_
#define TIMER0_NAMES_H_

typedef enum
{

 Normal_Mode=0,
 PWM_Phase_correct_Mode=64,
 CTC_Mode=8,
 Fast_PWM=72

} timer0_modes;

typedef enum
{
	timer0_stop,
	start_timer0_with_1_prescaler,
	start_timer0_with_8_prescaler,
	start_timer0_with_64_prescaler,
	start_timer0_with_256_prescaler,
	start_timer0_with_1024_prescaler,
	start_timer0_with_external_clock_falling_edge,
	start_timer0_with_external_clock_rising_edge,

}timer0_prescalers;

typedef enum
{

	non_inverting=2,
	inverting=3

}pwm_mode;
#endif /* TIMER0_NAMES_H_ */
