PROJECT		= main
CC			= /home/ufo/Developer/ATMEL/avr8-gnu-toolchain-linux_x86_64/bin/avr-gcc
CC_SIZE		= /home/ufo/Developer/ATMEL/avr8-gnu-toolchain-linux_x86_64/bin/avr-size
CC_OBJCOPY	= /home/ufo/Developer/ATMEL/avr8-gnu-toolchain-linux_x86_64/bin/avr-objcopy
CC_OBJDUMP	= /home/ufo/Developer/ATMEL/avr8-gnu-toolchain-linux_x86_64/bin/avr-objdump
FLAGS		= -Os 
C_FILES		= twi.c lcd.c
CPU			= atmega16

all: clean elf bin

%.elf: %.c
	$(CC) $(FLAGS) $< $(C_FILES) -mmcu=$(CPU) -o $@

elf: $(PROJECT).elf

%.bin: %.elf
	$(CC_OBJCOPY) -R .eeprom -O ihex $< $@

bin: $(PROJECT).bin

upload: main.bin
	avrdude -c usbasp -B 4 -p m16 -U flash:w:main.bin

size: $(PROJECT).elf
	$(CC_SIZE) $(PROJECT).elf

disasm: $(PROJECT).elf
	$(CC_OBJDUMP) -x $(PROJECT).elf

clean:
	rm -rf *.s *.o *.bin *.elf
