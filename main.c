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
u8 level=0;
select_output_pwm_mode(non_inverting);
adc_init();

//timer_0_write_on_ctc_reg(50);
//start_timer0(start_timer0_with_1024_prescaler);

while(1)

{
	//adc_convert(channel1);
u16 adc_read=adc_convert(channel1);

u8 duty_cycle=(float)adc_read*((float)100/(float)1023);
duty_cycle_set(duty_cycle);
  start_timer0(start_timer0_with_1024_prescaler);

	//key_read=key_pad_read();
	//_delay_ms(250);

	/*if(key_read!=0xff)
	{
		//level=key_read;
  duty_cycle_set(key_read-'0');
  start_timer0(start_timer0_with_1024_prescaler);
	}*/

	/*if(level!=0)
	{
		if(level=='A')
		{
			//select_timer0_mode(Fast_PWM);
			//select_output_pwm_mode(non_inverting);
			timer_0_write_on_ctc_reg(250);
			start_timer0(start_timer0_with_1024_prescaler);
		}
		if(level=='B')
				{
			           //select_timer0_mode(Fast_PWM);
						//select_output_pwm_mode(non_inverting);
					timer_0_write_on_ctc_reg(150);
					start_timer0(start_timer0_with_1024_prescaler);
				}
		if(level=='C')
				{
			    //select_timer0_mode(Fast_PWM);
						//select_output_pwm_mode(non_inverting);
					timer_0_write_on_ctc_reg(50);
					start_timer0(start_timer0_with_1024_prescaler);
				}

           level=0;
	}*/




}



}
