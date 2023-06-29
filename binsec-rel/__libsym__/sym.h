#define CAT(x,y) x##y

/* Call the functions*/
#define HIGH_INPUT(size) CAT(high_input_, size)
#define LOW_INPUT(size) CAT(low_input_, size)

/* Define the functions */
#define DEF_HIGH(size) void CAT(high_input_,size) (void* );
#define DEF_LOW(size) void CAT(low_input_,size) (void* );

DEF_HIGH(1)
DEF_LOW(1)

DEF_HIGH(2)
DEF_LOW(2)

DEF_HIGH(4)
DEF_LOW(4)

DEF_HIGH(8)
DEF_LOW(8)

DEF_HIGH(12)
DEF_LOW(12)

DEF_HIGH(16)
DEF_LOW(16)

DEF_HIGH(24)
DEF_LOW(24)

DEF_HIGH(32)
DEF_LOW(32)

DEF_HIGH(40)
DEF_LOW(40)

DEF_HIGH(48)
DEF_LOW(48)

DEF_HIGH(63)
DEF_LOW(63)

DEF_HIGH(64)
DEF_LOW(64)

DEF_HIGH(80)
DEF_LOW(80)

DEF_HIGH(96)
DEF_LOW(96)

DEF_HIGH(128)
DEF_LOW(128)

DEF_HIGH(160)
DEF_LOW(160)

DEF_HIGH(192)
DEF_LOW(192)

DEF_HIGH(200)
DEF_LOW(200)

DEF_HIGH(256)
DEF_LOW(256)

DEF_HIGH(240)
DEF_LOW(240)

DEF_HIGH(320)
DEF_LOW(320)

DEF_HIGH(384)
DEF_LOW(384)

DEF_HIGH(400)
DEF_LOW(400)

DEF_HIGH(500)
DEF_LOW(500)

DEF_HIGH(512)
DEF_LOW(512)

DEF_HIGH(600)
DEF_LOW(600)

DEF_HIGH(800)
DEF_LOW(800)

DEF_HIGH(1000)
DEF_LOW(1000)

DEF_HIGH(1024)
DEF_LOW(1024)

DEF_HIGH(1500)
DEF_LOW(1500)

DEF_HIGH(1536)
DEF_LOW(1536)

DEF_HIGH(2000)
DEF_LOW(2000)

DEF_HIGH(2048)
DEF_LOW(2048)

DEF_HIGH(2500)
DEF_LOW(2500)

DEF_HIGH(2560)
DEF_LOW(2560)

DEF_HIGH(3000)
DEF_LOW(3000)

DEF_HIGH(3072)
DEF_LOW(3072)

DEF_HIGH(131072)               /* 256 * 512 */
DEF_LOW(131072)                /* 256 * 512 */
