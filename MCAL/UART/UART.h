/*
 * UART.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Abdo Halem
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

/* Includes Section */
#include "../DIO/Dio.h"
#include "../INTERRUPT/Interrupt_cfg.h"
#include "UART_cfg.h"

/* Macros Declarations Section */


/* Function like Macro Section */
#define UART_TRANSMITTER_ENABLE()  (SET_BIT(UCSRB,TXEN))
#define UART_TRANSMITTER_DISABLE() (CLEAR_BIT(UCSRB,TXEN))

#define UART_TRANSMITTER_TXC_INTERRUPT_ENABLE()  (SET_BIT(UCSRB,TXCIE))
#define UART_TRANSMITTER_TXC_INTERRUPT_DISABLE() (CLEAR_BIT(UCSRB,TXCIE))

#define UART_TRANSMITTER_UDRIE_INTERRUPT_ENABLE()   (SET_BIT(UCSRA,UDRIE))
#define UART_TRANSMITTER_UDRIE_INTERRUPT_DISABLE()  (CLEAR_BIT(UCSRA,UDRIE))

#define UART_RECEIVER_ENABLE()  (SET_BIT(UCSRB,RXEN))
#define UART_RECEIVER_DISABLE() (CLEAR_BIT(UCSRB,RXEN))

#define UART_RECEIVER_RXC_INTERRUPT_ENABLE()  (SET_BIT(UCSRB,RXCIE))
#define UART_RECEIVER_RXC_INTERRUPT_DISABLE() (CLEAR_BIT(UCSRB,RXCIE))

#define UART_ASYNCHRONOUS_MODE_ENABLE() (UCSRC = (UCSRC | (1<<URSEL)) & (~(1<<UMSEL)))

#define UART_SYNCHRONOUS_MODE_ENABLE()  \
{\
	SET_BIT(UCSRC,URSEL); SET_BIT(UCSRC,UMSEL);\
}

#define UART_DISABLE_PARITY_MODE() \
{\
	SET_BIT(UCSRC,URSEL); CLEAR_BIT(UCSRC,UPM0); CLEAR_BIT(UCSRC,UPM1);\
}

#define UART_ENABLE_EVEN_PARITY()  \
{\
	SET_BIT(UCSRC,URSEL); CLEAR_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1);\
}

#define UART_ENABLE_ODD_PARITY() \
{\
	SET_BIT(UCSRC,URSEL); SET_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1);\
}

#define UART_1_STOP_BIT_SELECT() (UCSRC = (UCSRC | (1<<URSEL)) & (~(1<<USBS)))

#define UART_2_STOP_BIT_SELECT() (UCSRC = (1<<URSEL) | (1<<USBS) = 1)

#define UART_ASYNCHRONOUS_NORMAL_SPEED() (CLEAR_BIT(UCSRA,U2X))

#define UART_ASYNCHRONOUS_DOUBLE_SPEED() (SET_BIT(UCSRA,U2X))

#define UART_8_DATA_BITS_SELECT() (UCSRC = (UCSRC | (1<<URSEL)) | (1<<UCSZ1) | (1<<UCSZ0))
/* Data Type Declarations Section */

/* Software Interfaces Section */
void UART_init(void);
void UART_Init();
void UART_TransmiteByte_BLOCKING(uint8 data);
uint8 UART_ReceiveByte_BLOCKING();
void UART_SetCallBack(void (*fun)(void));
uint8 UART_ReceiveByteNoBlocking(void);

#endif /* MCAL_UART_UART_H_ */