#@Copyright : Kyrillos Sawiris
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2  -g
INCS=-I .
LIBS=
SRC =$(wildcard *.c)
OBJ =$(SRC:.c=.o)
As =$(wildcard *.s)
AsOBJ =$(As:.s=.o)
Project_Name=unit3_lab4_cortexM4


all: $(Project_Name).bin $(Project_Name).hex
	@echo "=============Build Done=============="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) -mthumb $< -o $@


$(Project_Name).elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=$(Project_Name).map
	
$(Project_Name).hex: $(Project_Name).elf
	$(CC)objcopy -O ihex $< $@


$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@		

clean:
	rm *.elf *.bin *.map	

clean_all:
	rm *.o *.elf *.bin *.map 
