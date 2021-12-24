#include <stdio.h>
/*
 * Properties for numbers which are powers of 2, is that they have one and only
 * one bit set in their binary representation. If the number is neither zero nor
 * a power of two, it will have 1 in more than one place. So if x is a power of
 * 2 then x & (x-1) will be 0.
 */
_Bool isPowerOfTwo(int n)
{
    return (n == 1 &&
            !(n & ((long)n - 1))); // -2147483648 - 1 will overflow int
}
