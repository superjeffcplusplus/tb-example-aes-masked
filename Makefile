#CC           = avr-gcc
#CFLAGS       = -Wall -mmcu=atmega16 -Os -Wl,-Map,test.map
#OBJCOPY      = avr-objcopy
CC           = gcc
LD           = gcc
AR           = ar
ARFLAGS      = rcs
CFLAGS       = -Wall -Os -c -g -fPIC -Wno-unused-function
LDFLAGS      = -Wall -Os -Wl,-Map,test.map -Wno-unused-function 

MASKED	   	 = 1

ifdef AES192
CFLAGS += -DAES192=1
endif
ifdef AES256
CFLAGS += -DAES256=1
endif
ifdef MASKED
CFLAGS += -DMASKED=1
endif

OBJCOPYFLAGS = -j .text -O ihex
OBJCOPY      = objcopy

# include path to AVR library
INCLUDE_PATH = /usr/lib/avr/include
# splint static check
SPLINT       = splint test.c aes.c -I$(INCLUDE_PATH) +charindex -unrecog

#default: test.elf

.SILENT:
.PHONY:  lint clean all

all: lib_ar

test.hex : test.elf
	echo copy object-code to new image and format in hex
	$(OBJCOPY) ${OBJCOPYFLAGS} $< $@

test.o : test.c aes.h aes.o
	echo [CC] $@ $(CFLAGS)
	$(CC) $(CFLAGS) -o  $@ $<

aes.o : aes.c aes.h
	echo [CC] $@ $(CFLAGS)
	$(CC) $(CFLAGS) -o $@ $<

libtinyaes.a : aes.o
	echo [AR] $@
	$(AR) $(ARFLAGS) $@ $^
lib_ar : libtinyaes.a

libtinyaes.so : aes.o
	echo [LD] $@
	$(LD) -shared -o $@ $^
lib_so : libtinyaes.so

aes32.o : aes.c aes.h
	echo [CC] $@ $(CFLAGS)
	$(CC) $(CFLAGS) -m32 -o $@ $<
libtinyaes_32bits.a : aes32.o
	echo [AR] $@
	$(AR) $(ARFLAGS) $@ $^
lib_ar_32 : libtinyaes_32bits.a

clean :
	rm -f *.OBJ *.LST *.o *.gch *.out *.hex *.map *.elf *.a *.so

test :
	make clean && make && ./test.elf
	make clean && make AES192=1 && ./test.elf
	make clean && make AES256=1 && ./test.elf

	make clean && make MASKED=1 && ./test.elf
	make clean && make MASKED=1 AES192=1 && ./test.elf
	make clean && make MASKED=1 AES256=1 && ./test.elf

test.elf : aes.o test.o
	echo [LD] $@
	$(LD) $(LDFLAGS) -o $@ $^

lint :
	$(call SPLINT)
