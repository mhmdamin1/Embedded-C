#include "uart.h"
unsigned char string_buffer[100]= "learn-in-depth:mohamed";
unsigned char const string_buffer[100]= "learn-in-depth:mohamed";
void main(void)
{
	uart_sendSTR(string_buffer);
	//string_buffer = &string_buffer[0]
}