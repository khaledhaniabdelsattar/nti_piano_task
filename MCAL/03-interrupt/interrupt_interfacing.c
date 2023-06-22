/*
 * interrupt_interfacing.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Khaled
 */

#include "interrupt_interfacing.h"

void enable_interrupts()
{

SET_BIT(SRGE_REGISTER,7);
}

void disable_interrupts()
{

CLEAR_BIT(SRGE_REGISTER,7);


}
