#include <stdio.h>
/* count digits, white space, others */
int main(void)
{
    int c, i, nwhite, nothers;
    int ndigits[10];
    nwhite = nothers = 0;
    for (i = 0; i < 10; ++i)
    {
        ndigits[i] = 0;
    }
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigits[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nothers;
    printf("digits:\n");
    for (i = 0; i < 10; ++i)
    {
        printf("%7d: %d\n", i, ndigits[i]);
    }
    printf("whitespace = %d, other = %d", nwhite, nothers);
    return 0;
}
