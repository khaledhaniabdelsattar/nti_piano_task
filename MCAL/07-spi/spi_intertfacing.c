/*
 * spi_intertfacing.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Khaled
 */
#include "spi_interfacing.h"

void Spi_MasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	DIO_cofigure_channel(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, output);
	/*	configure SPI SS Pin as output	*/
	DIO_cofigure_channel(SPI_SS_PORT, SPI_SS_CHANNEL, output);
	/*	configure SPI SCK Pin as output	*/
	DIO_cofigure_channel(SPI_SCK_PORT, SPI_SCK_CHANNEL, output);
	/*	configure SPI MISO Pin as input	*/
	DIO_cofigure_channel(SPI_MISO_PORT, SPI_MISO_CHANNEL, input);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	DIO_write_output_channel(SPI_SS_PORT, SPI_SS_CHANNEL, high);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	/*	set SCK frequency by F_CPU/16	*/
	/*	Set SPI Speed	*/
	SPI_SPCR_REG|=SPI_SCK_FREQ_FCPU_DIV_16;
}

void Spi_SlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	DIO_cofigure_channel(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, input);
	/*	configure SPI SS Pin as input	*/
	DIO_cofigure_channel(SPI_SS_PORT, SPI_SS_CHANNEL, input);
	/*	configure SPI SCK Pin as input	*/
	DIO_cofigure_channel(SPI_SCK_PORT, SPI_SCK_CHANNEL,  input);
	/*	configure SPI MISO Pin as output	*/
	DIO_cofigure_channel(SPI_MISO_PORT, SPI_MISO_CHANNEL, output);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Slave mode	*/
	CLEAR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
}

void Spi_MasterWrite (u8 data)
{
	/*	select slave	*/
	DIO_write_output_channel(SPI_SS_PORT , SPI_SS_CHANNEL, low);
	u8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)))
	{
		;
	}
		/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;
	/*	disable slave	*/
	DIO_write_output_channel(SPI_SS_PORT , SPI_SS_CHANNEL, high);
}


u8 Spi_MasterRead(void)
{
	u8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)))
	{
		;
	}
		/*	read the data register	*/
	return SPI_SPDR_REG;
}


u8 Spi_MasterTranseve(u8 data)
{
	/*	select slave	*/
		DIO_write_output_channel(SPI_SS_PORT , SPI_SS_CHANNEL, low);
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)))
	{
		;
	}
	/*	flush the data register	*/

	/*	disable slave	*/
		DIO_write_output_channel(SPI_SS_PORT , SPI_SS_CHANNEL, high);
	return SPI_SPDR_REG;
}

u8 Spi_SlaveRead(void)
{
	/*	wait until byte received	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)))
	{
		;
	}
		/*	read the data register	*/
	return SPI_SPDR_REG;
}

void Spi_SlaveWrite(u8 data)
{
	u8 loc_flush_byte;
		/*	load SPI data register with a byte to send	*/
		SPI_SPDR_REG = data;
		/*	wait until byte sent	*/
		while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)))
		{
			;
		}
			/*	flush the data register	*/
		loc_flush_byte = SPI_SPDR_REG;

}
