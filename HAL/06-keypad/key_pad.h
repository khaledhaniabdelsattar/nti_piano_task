/*
 * key_pad.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Khaled
 */

#ifndef KEY_PAD_H_
#define KEY_PAD_H_
#include "dio_interfacing.h"
#include "std_types.h"
#include "key_pad_names.h"

void key_pad_init();
u8 key_pad_read ();


#endif /* KEY_PAD_H_ */
