#include <stdio.h>
/* Count blanks, tabs, and newlines */

int main(void)
{
    int c, nb, nt, nl;
    nb = nt = nl = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    printf("%-10s: %d\n%-10s: %d\n%-10s: %d\n", "Blanks", nb, "Tabs", nt,
           "Newlines", nl);
    return 0;
}
