#include "c2_2.h"

unsigned int bitops_u32_c(unsigned int a,
                          unsigned int b,
                          unsigned int c,
                          unsigned int d)
{
    // Calculate ~(((a & b) | c) ^ d)
    unsigned int t1 = a & b;
    unsigned int t2 = t1 | c;
    unsigned int t3 = t2 ^ d;
    unsigned int result = ~t3;

    return result;
}
