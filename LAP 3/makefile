#
#	main.c
#
# Created on: jul 21, 2025
#      Author: Mohamed amin 
#


CC=arm-none-eabi-

CFLAGS=-mthumb -mcpu=cortex-m4 -gdwarf-2 -g

INCS=-I.
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)

Project_name=learn_in_depth-cortex-m4



all: $(Project_name).bin


%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	

clean_all:  
	rm *.o *.elf *.bin

clean: 
	rm *.elf *.bin
clean: 
	rm *.elf *.bin