#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    printf("Bits of type char: %d\n", CHAR_BIT);
    printf("Char max: %d, Char min: %d\n", CHAR_MAX, CHAR_MIN);
    printf("Unsigned char max: %d\n", (unsigned)UCHAR_MAX);
    printf("Short max: %d, Short min: %d\n", SHRT_MAX, SHRT_MIN);
    printf("Unsigned short max: %d\n", (unsigned)USHRT_MAX);
    printf("Int max: %d, int min: %d\n", INT_MAX, INT_MIN);
    printf("Unsigned int max: %u\n", UINT_MAX);
    printf("Long max: %ld, long min: %ld\n", LONG_MAX, LONG_MIN);
    printf("Unsigned long max: %lu\n", ULONG_MAX);
    return 0;
}
