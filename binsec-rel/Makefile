CC=gcc
LD=gcc

CFLAGS=-Wall -m32 -g -fno-stack-protector -static
#LD_FLAGS=-elf_i386

INCLUDE=-I../ -I./__libsym__/
CFLAGS+=$(INCLUDE)

LIB_SYM=-L./__libsym__/ -lsym
LIB_AES=-L../ -ltinyaes_32bits

BIN_ENC=targets/aes_enc_O0

BIN_ENC_2=targets/aes_enc_2

all: $(BIN_ENC) $(BIN_ENC_2)

$(BIN_ENC): target-aes_encrypt.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIB_SYM) $(LIB_AES)

$(BIN_ENC_2): aes_ecb_enc_wrapper.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIB_AES)

#clean:
#	rm -rf *.o *.csv *.out smtdir/*/*.smt2 $(BIN_ENC)

clean:
	rm -f $(BIN_ENC) $(BIN_ENC_2)