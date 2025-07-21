/*
 *	linker.ld
 *
 *  Created on: jul 21, 2025
 *      Author: Mohamed amin 
 */

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000 , LENGTH = 128K 
	SRAM (rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text : 
	{
		startup.o(.vextors) 
		*(.vectors*) 
		*(.text)
		*(.text*)
		*(.rodata)
		. = ALIGN(4) ;
		_E_text = . ;
	} > FLASH
	
	.data : 
	{
		_S_data = .;
		*(.data)
		*(.data*)
		. = ALIGN(4) ;
		_E_data = . ;
	} > SRAM AT> FLASH
	
	.bss : 
	{
		_S_bss = . ;
		*(.bss)
		*(.bss*)
		. = ALIGN(4) ;
		_E_bss = . ;
	} > SRAM
}