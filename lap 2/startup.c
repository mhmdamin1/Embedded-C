//MOHAMED AMIIN 

#include <stdint.h>

#define Stack_start 0x20001000
extern int main (void);
void Rest_handler(void);



static unsigned long _stack_top[256];

void Default_Handler(void)
{
	Rest_handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;
void Bus_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;




void (* const g_p_fn_vectors[]) () __attribute__((section(".vectors"))) = {
	(void(*const)()) ((uint32_t)_stack_top + sizeof(_stack_top)),
	&Rest_handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler
};



extern unsigned long _S_DATA;
extern unsigned long _E_DATA;
extern unsigned long _S_bss;
extern unsigned long _E_bss;
extern unsigned long _E_text;


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