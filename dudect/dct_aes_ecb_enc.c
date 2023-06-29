//
// Created by Jeff on 28.06.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <aes.h>

#define DUDECT_IMPLEMENTATION
#include "dudect.h"

/* target function to check for constant time */
int check_tag(uint8_t *x, uint8_t *y, size_t len) {
    return memcmp(x, y, len);
}

#define SECRET_LEN_BYTES (16)
#define AES_BLOCK_LEN (16)

int memcmp(const void *s1, const void *s2, size_t n)
{
    const char *p1 = (const char *)s1, *p2 = (const char *)s2;
    int res = 0;
    for (size_t i = 0; i < n; i += 1) {
        res = res | (~(res >> 31) & ((res - 1) >> 31) & (p1[i] - p2[i]));
    }
    return res;
}

uint8_t secret[SECRET_LEN_BYTES] = {0, 1, 2, 3, 4, 5, 6, 42};
struct AES_ctx ctx;
uint8_t clear_text[AES_BLOCK_LEN];
uint8_t clear_text_cp[AES_BLOCK_LEN];


/* this will be called over and over */
uint8_t do_one_computation(uint8_t *data) {
    AES_ECB_encrypt(&ctx, data);
    int res = memcmp(clear_text, clear_text_cp, AES_BLOCK_LEN);

    /* ensure the result is in [-1..1] */
    res |= res >> 1;
    res |= res >> 2;
    res |= res >> 4;
    res |= res >> 8;
    res |= res >> 16;
    res = (res & 1) | (res >> 31);

    return (uint8_t) res;
}

/* called once per number_measurements */
void prepare_inputs(dudect_config_t *c, uint8_t *input_data, uint8_t *classes) {
    randombytes(input_data, c->number_measurements * c->chunk_size);
    for (size_t i = 0; i < c->number_measurements; i++) {
        /* it is important to randomize the class sequence */
        classes[i] = randombit();
        if (classes[i] == 0) {
            memset(input_data + (size_t)i * c->chunk_size, 0x00, c->chunk_size);
        } else {
            // leave random
        }
    }
}

int run_test(void) {
    dudect_config_t config = {
            .chunk_size = AES_BLOCK_LEN,
#ifdef MEASUREMENTS_PER_CHUNK
            .number_measurements = MEASUREMENTS_PER_CHUNK,
#else
            .number_measurements = 500,
#endif
    };
    dudect_ctx_t ctx;

    dudect_init(&ctx, &config);

    /*
    Call dudect_main() until
     - returns something different than DUDECT_NO_LEAKAGE_EVIDENCE_YET, or
     - you spent too much time testing and give up
    Recommended that you wrap this program with timeout(2) if you don't
    have infinite time.
    For example this will run for 20 mins:
      $ timeout 1200 ./your-executable
    */
    dudect_state_t state = DUDECT_NO_LEAKAGE_EVIDENCE_YET;
    while (state == DUDECT_NO_LEAKAGE_EVIDENCE_YET) {
        state = dudect_main(&ctx);
    }
    dudect_free(&ctx);
    return (int)state;
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    run_test();
}