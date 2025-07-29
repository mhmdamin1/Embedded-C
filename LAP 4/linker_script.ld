/*
Linker script CortexM3
BY MOHAMED AMIN AFIFY
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
		_E_text = . ;
	} >flash
	
	.data : 
	{
		_S_DATA = . ;
		*(.data*)
		*(.data.*)
		_E_DATA = . ;
	}>sram AT> flash
	
	.bss : 
	{
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = . ;
		
		
		
	} >sram
	. = . + 0x1000 ;
	. = ALIGN(4);
	_END_HEAP = .;
	
	. = . + 0x1000 ;
	. = ALIGN(4);
	_stack_top = .;
	
	.debug :
	{
		*(.debug*)
		*(.debug.*)
	}
}