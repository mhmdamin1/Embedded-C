#include "uart.h"


#define UART0DR *((volatile unsigned int* )((unsigned int* )0x101f1000))

void uart_sendSTR (unsigned char* p_tx_str){

	while(*p_tx_str != '\0'){
		UART0DR = (unsigned int)(*p_tx_str);
		p_tx_str++;
	}
}
