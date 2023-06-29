CC=gcc
LD=gcc

CFLAGS=-Wall -O0

INCLUDE=-I../
CFLAGS+=$(INCLUDE)

LIB_AES=-L../ -ltinyaes

BIN_ENC=bin/aes_ecb_enc

all: $(BIN_ENC)

$(BIN_ENC): dct_aes_ecb_enc.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIB_AES)

clean:
	rm -f $(BIN_ENC)