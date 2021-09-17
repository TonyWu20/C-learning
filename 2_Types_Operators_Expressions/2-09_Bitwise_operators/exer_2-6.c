#include <stdio.h>

/* getbits: get n bits from position p*/
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(void)
{
    int x, p, n;
    x = 20; /* 20 = 10100*/
    p = 4;
    n = 3;
    unsigned res = getbits(x, p, n);
    printf("X = %d get %d bits begins at position %d = %d", x, n, p, res);
}
