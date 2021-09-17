#include <stdio.h>

int lower(int c);
int old_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
int lower(int c) /* new version of lower with conditional expression */
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(lower(c));
}
