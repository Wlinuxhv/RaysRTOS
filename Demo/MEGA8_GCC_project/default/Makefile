###############################################################################
# Makefile for the project RaySRTOS
###############################################################################

## General Flags
PROJECT = RaySRTOS
MCU = atmega8
TARGET = RaySRTOS.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99           -DF_CPU=1000000UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=RaySRTOS.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"D:\RaySRTOS\Demo\MEGA8_GCC_project\..\..\CPU\AVR_GCC" -I"D:\RaySRTOS\Demo\MEGA8_GCC_project\..\..\Kernel" 

## Objects that must be built in order to link
OBJECTS = main.o RaysRTOS.o CPU_ASM.o CPU.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) RaySRTOS.hex RaySRTOS.eep RaySRTOS.lss size

## Compile
main.o: ../main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

RaysRTOS.o: ../../../Kernel/RaysRTOS.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CPU_ASM.o: ../../../CPU/AVR_GCC/CPU_ASM.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CPU.o: ../../../CPU/AVR_GCC/CPU.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) RaySRTOS.elf dep/* RaySRTOS.hex RaySRTOS.eep RaySRTOS.lss RaySRTOS.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

