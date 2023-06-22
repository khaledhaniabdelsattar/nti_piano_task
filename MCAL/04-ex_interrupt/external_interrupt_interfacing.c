/*
 * external_interrupt_interfacing.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Khaled
 */

#include "external_interrupt_interfacing.h"

void(*ptr_int0)(void)=NULL;
void(*ptr_int1)(void)=NULL;
void(*ptr_int2)(void)=NULL;

void enable_EXT_interrupt_channel(EXT_interrupts_channel channel)
{

	switch (channel)
	{

	case EXT_interrupt_INT0:

		SET_BIT(GICR__EX_interrupts_reg,6);

		break;

	case EXT_interrupt_INT1:

			SET_BIT(GICR__EX_interrupts_reg,7);

			break;

	case EXT_interrupt_INT2:

			SET_BIT(GICR__EX_interrupts_reg,5);

			break;

}

}



void disable_EXT_interrupt_channel(EXT_interrupts_channel channel)
{

	switch (channel)
		{

		case EXT_interrupt_INT0:

			CLEAR_BIT(GICR__EX_interrupts_reg,6);

			break;

		case EXT_interrupt_INT1:

			CLEAR_BIT(GICR__EX_interrupts_reg,7);

				break;

		case EXT_interrupt_INT2:

			CLEAR_BIT(GICR__EX_interrupts_reg,5);

				break;

	}

}

void sellect_EXT_interrupt_channel_mode(EXT_interrupts_channel channel,EXT_interrupts_modes mode)
{

	if(channel==EXT_interrupt_INT0)
	{

		MCUCR_EX_interrupts_reg=(MCUCR_EX_interrupts_reg)|(mode);

	}

	if(channel==EXT_interrupt_INT1)
		{

			MCUCR_EX_interrupts_reg=(MCUCR_EX_interrupts_reg)|(mode<<2);

		}


	if(channel==EXT_interrupt_INT2)
	{

		if(mode==rising_edge)
		{

			CLEAR_BIT(MCUCSR_EX_interrupts_reg,6);

		}

		 if(mode==falling_edge)
				{

				   SET_BIT(MCUCSR_EX_interrupts_reg,6);

				}

		 if(mode==low_level)

		 {




		 }

		 if(mode==both_edges)

		 		 {




		 		 }


	}

}

void calling_interrupt0(void(*ptr_int)(void))
{


 if(ptr_int!=NULL)
 {

	 ptr_int0=ptr_int;

 }

}
void calling_interrupt1(void(*ptr_int)(void))
{


 if(ptr_int!=NULL)
 {

	 ptr_int1=ptr_int;

 }

}

void calling_interrupt2(void(*ptr_int)(void))
{

if(ptr_int!=NULL)
 {

	 ptr_int2=ptr_int;

 }

}


ISR(INT0_vect)

{


	ptr_int0();

}

ISR(INT1_vect)

{


	ptr_int1();

}

ISR(INT2_vect)

{

 ptr_int2();

}



