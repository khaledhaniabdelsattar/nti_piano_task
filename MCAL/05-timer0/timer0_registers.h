/*
 * timer0_registers.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Khaled
 */

#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_

#include "std_types.h"
// (*(volatile u8*)(0x3B))

#define TIMER0_CONTROL_REG             (*(volatile u8*)(0x53))
#define TIMER0_VALUE_REG               (*(volatile u8*)(0x52))
#define TIMER0_COMPARE_REG             (*(volatile u8*)(0x5c))
#define TIMER0_INTERRUPT_MASK_REG      (*(volatile u8*)(0x59))
#define TIMER0_INTERRUPT_FLAG_REG      (*(volatile u8*)(0x58))


#endif /* TIMER0_REGISTERS_H_ */
