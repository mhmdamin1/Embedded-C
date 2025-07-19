#by : mohamed amin
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS= -I . 
LIBS= 
SCR= $(wildcard *.c)
OBJ= $(SCR:.c=.o)
As= $(wildcard *.s)
AsOBJ = $(As:.s=.o) 
Project_name=learn-in-depth_cortex_m3

all : $(Project_name).bin

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
$(Project_name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=map_file.map
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all: 
	rm *.o *.elf *.bin
	
clean: 
	rm *.elf *.bin