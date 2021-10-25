/*
 * M8_UART.h
 *
 * Created: 2021-1-26
 *  Author: Pata
 *
 *
 *
 *						Atmega8 pin map
 *
 *				 RESET  = PC6   PC5 =
 *					RX	= PD0   PC4 =
 *					TX	= PD1   PC3 =
 *						= PD2   PC2 =
 *						= PD3   PC1 =
 *						= PD4   PC0 =
 *				 VCC	= VCC   GND =
 *				 GND	= GND   AREF=
 *						= PB6   AVCC=
 *            			= PB7   PB5 =
 *			  			= PD5   PB4 =
 *						= PD6   PB3 =
 *						= PD7   PB2 =
 *						= PB0   PB1 =
 *
 */ 

#ifndef PATA_UART_H_
#define PATA_UART_H_
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define TX		0x01
#define RX		0x02
#define TXRX	0x03
#define RXI		0x04
#define TXRXI	0x05

#define BAUD_9600	1
#define BAUD_14k	2
#define BAUD_19k	3
#define BAUD_38k	4


// UART initialize
void UART_init(uint8_t baud, uint8_t mode);

// Standard TX/RX
void UART_tx(uint8_t data);
void UART_tx_m(uint8_t *data, uint8_t length);
uint8_t UART_rx();
void UART_rx_m(uint8_t *data, uint8_t length);
void UART_NWL();



#endif /* PATA_UART_H_ */