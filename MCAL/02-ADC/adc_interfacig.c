/*
 * adc_interfacig.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Khaled
 */

#include "adc_interfacing.h"



void adc_enable_interrupt()

{

	SET_BIT(ADC_sra,ADC_PIN3);
}

void adc_disable_interrupt()

{

	 CLEAR_BIT(ADC_sra,ADC_PIN3);

}


u16  read_adc_channel()
{

u16 read=(ADCl)|(ADCH<<8);

return read;
}

void adc_selecting_channel(adc_channel channel)

{

	ADC_mux=(ADC_mux&0xE0)|channel; //selecting the channel

}

void adc_start_convertion()

{

SET_BIT(ADC_sra,ADC_PIN6); //start convertion


}

void adc_init()

{

	//enable
//clock
// left adjast
// vref


	//clock with prescaler 128 //enable
	ADC_sra=(ADC_sra)|135; //              1000 0111

	// left adjast
  CLEAR_BIT(ADC_mux,ADC_PIN5);

  // vref
   ADC_mux=(ADC_mux)|(1<<6);

}

u16 adc_convert(adc_channel channel)
{

//ADC_mux=(ADC_mux&0xE0)|channel; //selecting the channel

adc_selecting_channel(channel);

//SET_BIT(ADC_sra,ADC_PIN6); //start convertion

adc_start_convertion();

while(CHECK_BIT(ADC_sra,ADC_PIN4)==0);

SET_BIT(ADC_sra,ADC_PIN4);// clear flag by 1!!!!!

return read_adc_channel();

}

f32 adc_analoge_read(u16 read,u8 vref)
{

	f32 analoge_read=(read)*((f32) vref/1024);

 return analoge_read;
}
