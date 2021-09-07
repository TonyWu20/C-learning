#include <stdio.h>

#define TABSTOP 4

int main(void)
{
    int c, spacecount, i;

    spacecount = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++spacecount;
            if ((spacecount % TABSTOP) == 0)
                putchar('\t');
        }
        else
        {
            for (i = 0; i < (spacecount % TABSTOP); ++i)
                putchar(' ');
            putchar(c);
            if (spacecount != 0)
                spacecount = 0;
        }
    }
}
