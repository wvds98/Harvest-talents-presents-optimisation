#include "xorshift.h"
//Marsaglia xorshift 0 to 64
uint32_t xor_state = 37593425;
uint32_t xorshift_0_64() {
    xor_state ^= (xor_state << 13);
    xor_state ^= (xor_state >> 17);
    xor_state ^= (xor_state << 5);
    return xor_state & 0x3F;
}
