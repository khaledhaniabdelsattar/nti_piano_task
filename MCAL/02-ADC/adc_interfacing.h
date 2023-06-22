/*
 * adc_interfacing.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Khaled
 */

#ifndef ADC_INTERFACING_H_
#define ADC_INTERFACING_H_

#include "adc_register.h"
#include "bitmath.h"
#include "adc_types.h"

void adc_init();
void adc_enable_interrupt();
void adc_disable_interrupt();
u16 read_adc_channel();
void adc_selecting_channel(adc_channel channel);
void adc_start_convertion();
u16 adc_convert(adc_channel channel);
f32 adc_analoge_read(u16 read,u8 vref);




#endif /* ADC_INTERFACING_H_ */
