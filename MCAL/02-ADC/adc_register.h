/*
 * adc_register.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Khaled
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#include "std_types.h"

#define ADC_mux     (*(volatile u8*)(0x27))
#define ADC_sra     (*(volatile u8*)(0x26))
#define ADCH        (*(volatile u8*)(0x25))
#define ADCl        (*(volatile u8*)(0x24))




#endif /* ADC_REGISTER_H_ */
