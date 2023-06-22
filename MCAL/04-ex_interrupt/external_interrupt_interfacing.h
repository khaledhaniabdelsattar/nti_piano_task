/*
 * external_interrupt_interfacing.h
 *
 *  Created on: Jul 1, 2022
 *      Author: Khaled
 */

#ifndef EXTERNAL_INTERRUPT_INTERFACING_H_
#define EXTERNAL_INTERRUPT_INTERFACING_H_

#include "bitmath.h"
#include "std_types.h"
#include "external_interrupt_register.h"
#include "interrupt_register.h"
#include  "external_interrupt_names.h"
#include <avr/interrupt.h>
#include <stdio.h>

void enable_EXT_interrupt_channel(EXT_interrupts_channel channel);
void disable_EXT_interrupt_channel(EXT_interrupts_channel channel);
void sellect_EXT_interrupt_channel_mode(EXT_interrupts_channel channel,EXT_interrupts_modes mode);
void calling_interrupt0(void(*ptr_int)(void));
void calling_interrupt1(void(*ptr_int)(void));
void calling_interrupt2(void(*ptr_int)(void));

#endif /* EXTERNAL_INTERRUPT_INTERFACING_H_ */
