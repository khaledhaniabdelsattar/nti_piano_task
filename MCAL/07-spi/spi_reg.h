/*
 * spi_reg.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Khaled
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_
#include "std_types.h"

#define SPI_SPCR_REG 			(*(volatile u8*)0x2D)
#define SPI_SPSR_REG			(*(volatile u8*)0x2E)
#define SPI_SPDR_REG			(*(volatile u8*)0x2F)

#define SPI_SPE_BIT_NO           	(6)
#define SPI_MSTR_BIT_NO				(4)
#define SPI_SPIF_BIT_NO				(7)



#endif /* SPI_REG_H_ */
