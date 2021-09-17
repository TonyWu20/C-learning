#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int maxline);
int main(void)
{
    int len;
    char s[MAXLINE];
    while ((len = my_getline(s, MAXLINE)) > 0)
        printf("%s\n", s);
    return 0;
}
int my_getline(char s[], int maxline)
{
    int c, i;
    i = 0;
    while (i < maxline - 1)
    {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            s[i] = '\n';
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
