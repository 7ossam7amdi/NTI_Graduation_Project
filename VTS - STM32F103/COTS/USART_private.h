
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;		//Status Register
	volatile u32 DR;		//Data Register
	volatile u32 BRR;		//Baud rate Register
	volatile u32 CR[3];		//Control Registers
	volatile u32 GTPR;		//Guard time and prescaler Register
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)

typedef enum
{
	SBK,
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE
}CR_Bits;

typedef enum
{
	PE,
	FE,
	NE,
	ORE,
	IDLE,
	RXNE,
	TC,
	TXE,
	LBD,
	CTS
}SR_Bits;

#define UART_BAUDRATE_9600		0x341

#endif
