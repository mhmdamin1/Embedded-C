//MOHAMED AMIN

#include <stdint.h>

#define Stack_start 0x20001000
extern int main (void);
void Rest_handler(void);


extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern unsigned int _stack_top;


void Default_Handler(void)
{
	Rest_handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void Bus_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;



uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) & _stack_top,
	(uint32_t) &Rest_handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault_Handler
	
};




void Rest_handler(void)
{
	/* copy data from ROM to RAM */
	unsigned int DATA_SIZE = (unsigned int*)&_E_DATA - (unsigned int*)&_S_DATA;
	unsigned int* p_scr = (unsigned int*) &_E_text;	
	unsigned int* p_des = (unsigned int*) &_S_DATA;	
	for(int i = 0; i < DATA_SIZE; i++)
	{
		*((unsigned int*)p_des++) = *((unsigned int*)p_scr++);
	}
	
	
	/* Reserve and init the bss */
	unsigned int BSS_SIZE = (unsigned int*)& _E_bss - (unsigned int*) & _S_bss;
	p_des = (unsigned int*) &_S_bss;
	for(int i = 0; i  < BSS_SIZE; i++)
	{
		*((unsigned int*)p_des) = (unsigned int)0;
	}
	/* Jump to main */
	main();
}