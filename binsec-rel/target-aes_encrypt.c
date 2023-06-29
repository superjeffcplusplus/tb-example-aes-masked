//
// Created by Jeff on 28.06.23.
//
#include <stdint.h>

#include "./__libsym__/sym.h"
#include <aes.h>

#define KEY_LEN 16
#define AES_BLOCK_LEN 16

uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16,
                  0x28, 0xae, 0xd2, 0xa6,
                  0xab, 0xf7, 0x15, 0x88,
                  0x09, 0xcf, 0x4f, 0x3c };

int main(void) {

    struct AES_ctx ctx;
    uint8_t clear_text[AES_BLOCK_LEN];
    AES_init_ctx(&ctx, key);

    low_input_16(clear_text);
    high_input_16(&ctx.RoundKey);

    AES_ECB_encrypt(&ctx, clear_text);

    return 0;

}

