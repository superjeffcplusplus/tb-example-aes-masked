#include <stdint.h>
#include <stdio.h>

#include <aes.h>

uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16,
                  0x28, 0xae, 0xd2, 0xa6,
                  0xab, 0xf7, 0x15, 0x88,
                  0x09, 0xcf, 0x4f, 0x3c };

struct AES_ctx ctx;

#define MW_AES_BLOCK_LEN 16

extern void RunTarget(FILE* input)
{
	// TODO Read test case and execute target primitive
	
	// Everything in this function is traced.

	// Avoid calling a library's debug output functionality outside clear error conditions:
	// These functions can produce _a lot_ of trace entries and, as they are almost certainly
	// not constant-time, they may also generate a considerable number of false positives.
	// printf() and others I/O functionality from the C standard library are _usually_ fine,
	// as this library is skipped during the analysis by default.
	
    uint8_t data[MW_AES_BLOCK_LEN];
    if(fread(data, 1, MW_AES_BLOCK_LEN, input) != MW_AES_BLOCK_LEN)
        return;

    //void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);
    AES_ECB_encrypt(&ctx, data);
}

extern void InitTarget(FILE* input)
{
	// TODO Initialize library
	
	// This function is called once before running the first test case.
	// In some scenarios, especially if there isn't a dedicated initialization function, it
	// is best to just run the first test case, which is why this method receives a file handle
	// for the first test case file:
	// RunTarget(input);
	
	// You should really avoid that a part of the library gets initialized late, as this may
	// generate false positives.
	
	// Fortunality, this library has an initialization function!

    AES_init_ctx(&ctx, key);

}