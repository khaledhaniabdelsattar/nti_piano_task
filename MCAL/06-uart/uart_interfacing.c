/*
 * uart_interfacing.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Khaled
 */

#include "uart_interfacing.h"



void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;
	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
}


void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}


u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	if ((CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
	{
		return UART_UDR_REG;
	}
	else
	{
		return 0;
	}
	/* Get and return received data from buffer */

}

void UART_TransmitStr(u8 *str)
{
	/* Wait for empty transmit buffer */
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}
