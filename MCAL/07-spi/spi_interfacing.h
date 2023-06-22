/*
 * spi_interfacing.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Khaled
 */

#ifndef SPI_INTERFACING_H_
#define SPI_INTERFACING_H_
#include "std_types.h"
#include "bitmath.h"
#include "spi_cfg.h"
#include "spi_reg.h"
#include "dio_interfacing.h"

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)


void Spi_MasterInit(void);
void Spi_SlaveInit(void);
void Spi_MasterWrite(u8 data);
u8 Spi_MasterRead(void);
u8 Spi_MasterTranseve(u8 data);
u8 Spi_SlaveRead(void);
void Spi_SlaveWrite(u8 data);





#endif /* SPI_INTERFACING_H_ */
