#include "calc.h"
#include <ctype.h>
#include <stdio.h>
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-')
    {
        s[i] = c;
        if (!isdigit(c = getch())) /* next character after '-' */
            return '-';
        else
            s[++i] = c;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c =
                           getch())) /* get next char, stored in next position
                                        in s, determine if is digit */
            ;                        /* if is number, continue */
    if (c == '.')                    /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
