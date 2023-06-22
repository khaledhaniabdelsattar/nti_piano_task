/*
 * external_interrupt_names.h
 *
 *  Created on: Jul 3, 2022
 *      Author: Khaled
 */

#ifndef EXTERNAL_INTERRUPT_NAMES_H_
#define EXTERNAL_INTERRUPT_NAMES_H_

typedef enum

{

EXT_interrupt_INT0,
EXT_interrupt_INT1,
EXT_interrupt_INT2

}EXT_interrupts_channel;


typedef enum

{

low_level,
both_edges,
falling_edge,
rising_edge

}EXT_interrupts_modes;


#endif /* EXTERNAL_INTERRUPT_NAMES_H_ */
