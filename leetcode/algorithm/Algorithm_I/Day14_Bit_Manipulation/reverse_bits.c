#include <stdint.h>
#include <stdio.h>

/**
 * 12 = (1100)
 * rev = 0000
 * n >>= 1 = 0011
 * rev = 0001 n >>=1 = 0001
 * rev<<=1 0010 0011 n >>=1 = 0000
 */
uint32_t reverseBits(uint32_t n)
{
    uint32_t rev = 0;
    int count = 32;
    while (count > 0)
    {
        rev <<= 1;
        if ((n & 1) == 1)
            rev ^= 1;
        n >>= 1;
        count--;
    }
    rev += n & 1;
    return rev;
}
