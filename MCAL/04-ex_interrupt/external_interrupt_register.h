/*
 * external_interrupt_register.h
 *
 *  Created on: Jul 1, 2022
 *      Author: Khaled
 */

#ifndef EXTERNAL_INTERRUPT_REGISTER_H_
#define EXTERNAL_INTERRUPT_REGISTER_H_

#include "std_types.h"

#define MCUCR_EX_interrupts_reg     (*(volatile u8*)(0x55))
#define MCUCSR_EX_interrupts_reg    (*(volatile u8*)(0x54))
#define GICR__EX_interrupts_reg     (*(volatile u8*)(0x5B))
#define GIFR__EX_interrupts_reg     (*(volatile u8*)(0x5A))

#endif /* EXTERNAL_INTERRUPT_REGISTER_H_ */
