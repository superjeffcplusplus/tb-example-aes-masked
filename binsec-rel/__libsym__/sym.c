#if defined(__clang__)
#define ATTRIBUTE __attribute__((optnone))
#else
# define ATTRIBUTE __attribute__((optimize("-O0")))
#endif
#include <unistd.h>

#define CAT(x,y) x##y

/* Declare functions */
/* Warning -> Add function in sym.h */
#define DECL_HIGH(size) ATTRIBUTE void CAT(high_input_,size) (void* tab){ read(STDIN_FILENO, tab, size); }
#define DECL_LOW(size) ATTRIBUTE void CAT(low_input_,size) (void* tab){ read(STDIN_FILENO, tab, size); }

DECL_HIGH(1)
DECL_LOW(1)

DECL_HIGH(2)
DECL_LOW(2)

DECL_HIGH(4)
DECL_LOW(4)

DECL_HIGH(8)
DECL_LOW(8)

DECL_HIGH(12)
DECL_LOW(12)

DECL_HIGH(16)
DECL_LOW(16)

DECL_HIGH(24)
DECL_LOW(24)

DECL_HIGH(32)
DECL_LOW(32)

DECL_HIGH(40)
DECL_LOW(40)

DECL_HIGH(48)
DECL_LOW(48)

DECL_HIGH(63)
DECL_LOW(63)
 
DECL_HIGH(64)
DECL_LOW(64)

DECL_HIGH(80)
DECL_LOW(80)

DECL_HIGH(96)
DECL_LOW(96)

DECL_HIGH(128)
DECL_LOW(128)

DECL_HIGH(160)
DECL_LOW(160)

DECL_HIGH(192)
DECL_LOW(192)

DECL_HIGH(200)
DECL_LOW(200)

DECL_HIGH(256)
DECL_LOW(256)

DECL_HIGH(240)
DECL_LOW(240)

DECL_HIGH(320)
DECL_LOW(320)

DECL_HIGH(384)
DECL_LOW(384)

DECL_HIGH(400)
DECL_LOW(400)

DECL_HIGH(500)
DECL_LOW(500)

DECL_HIGH(512)
DECL_LOW(512)

DECL_HIGH(600)
DECL_LOW(600)

DECL_HIGH(800)
DECL_LOW(800)

DECL_HIGH(1000)
DECL_LOW(1000)

DECL_HIGH(1024)
DECL_LOW(1024)

DECL_HIGH(1500)
DECL_LOW(1500)

DECL_HIGH(1536)
DECL_LOW(1536)

DECL_HIGH(2000)
DECL_LOW(2000)

DECL_HIGH(2048)
DECL_LOW(2048)

DECL_HIGH(2500)
DECL_LOW(2500)

DECL_HIGH(2560)
DECL_LOW(2560)

DECL_HIGH(3000)
DECL_LOW(3000)

DECL_HIGH(3072)
DECL_LOW(3072)

DECL_HIGH(131072)               /* 256 * 512 */
DECL_LOW(131072)                /* 256 * 512 */
