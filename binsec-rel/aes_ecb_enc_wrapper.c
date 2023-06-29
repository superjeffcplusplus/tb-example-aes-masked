//
// Created by Jeff on 28.06.23.
//

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include <aes.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    const char *p1 = (const char *)s1, *p2 = (const char *)s2;
    int res = 0;
    for (size_t i = 0; i < n; i += 1) {
        res = res | (~(res >> 31) & ((res - 1) >> 31) & (p1[i] - p2[i]));
    }
    return res;
}

#define KEY_LEN 16
#define AES_BLOCK_LEN 16

uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16,
                  0x28, 0xae, 0xd2, 0xa6,
                  0xab, 0xf7, 0x15, 0x88,
                  0x09, 0xcf, 0x4f, 0x3c };

uint8_t clear_text[AES_BLOCK_LEN];
struct AES_ctx ctx;

int main(void) {

    uint8_t clear_text_cp[AES_BLOCK_LEN];
    for (size_t i = 0; i < AES_BLOCK_LEN; i += 1) {
        clear_text_cp[i] = clear_text[i];
    }
    AES_init_ctx(&ctx, key);
    AES_ECB_encrypt(&ctx, clear_text);
    int res = memcmp(clear_text, clear_text_cp, AES_BLOCK_LEN);

    /* ensure the result is in [-1..1] */
    res |= res >> 1;
    res |= res >> 2;
    res |= res >> 4;
    res |= res >> 8;
    res |= res >> 16;
    res = (res & 1) | (res >> 31);

    exit(res);
}