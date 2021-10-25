/*
 * M8_UART.c
 *
 * Created: 2021-12-26
 *  Author: Pata
 */ 
#include <avr/io.h>
#include "pata_UART.h"
#include <stdint.h>

volatile uint8_t data = 0;
volatile uint8_t data_m[10] = {0};
uint8_t ubrr = 0;


void UART_init(uint8_t baud, uint8_t mode)
{
	switch (baud)
	{
		case 1:
			ubrr = 51;
			break;
		case 2:
			ubrr = 34;
			break;
		case 3:
			ubrr = 25;
			break;
		case 4:
			ubrr = 12;
			break;
	}
	UBRRH = (ubrr >> 8);
	UBRRL = ubrr;
	
	if (mode & TX)
		UCSRB = (1 << TXEN);
	if ((mode & RX) || (mode & RXI))
		UCSRB |= (1 << RXEN);
	if (mode & RXI)
		UCSRB |= (1 << RXCIE);
	
	DDRD &= ~(1<<0);
	DDRD |= (1<<1);
	
}

void UART_tx(uint8_t data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
	
}

void UART_tx_m(uint8_t *data, uint8_t length)
{
	for (uint8_t i = 0; i < length; i++)
	{
		while(!(UCSRA & (1<<UDRE)));
		UDR = data[i];
	}
	
}

uint8_t UART_rx()
{
	while (!(UCSRA & (1<<RXC)));
	data = UDR;
	
	return data;
	
}

void UART_rx_m(uint8_t *data, uint8_t length)
{
	for (uint8_t i = 0; i < length; i++)
	{
		while(!(UCSRA & (1<<RXC)));
		UDR = data[i];
	}
	
}