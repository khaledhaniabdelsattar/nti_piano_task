/*
 * main.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Khaled
 */
#include "dio_interfacing.h"
#include "led_interface.h"
#include "timer0_interfacing.h"
#include "key_pad.h"
#include "adc_interfacing.h"
#include <util/delay.h>

void main ()
{

DIO_cofigure_channel(PORTB, PIN3, output);

select_timer0_mode(PWM_Phase_correct_Mode);
u8 key_read=0;
select_output_pwm_mode(non_inverting);




while(1)

{
	
	key_read=key_pad_read();
	_delay_ms(250);

	if(key_read!=0xff)
	{
		
  duty_cycle_set(key_read-'0');
  start_timer0(start_timer0_with_1024_prescaler);
	}




}



}
