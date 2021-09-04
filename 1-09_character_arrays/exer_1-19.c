#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int my_getline(char line[], int maxline);
void reverse(char to[], char from[], int length);

int main()
{
    int len;
    char line[MAXLINE];
    char rev[MAXLINE];
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        reverse(rev, line, len);
        printf("%s", rev);
    }
    return 0;
}
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = EOF;
    return i;
}
void reverse(char to[], char from[], int len_line)
{
    int i, j;
    j = 0;
    for (i = len_line - 2; i >= 0 && i < MAXLINE - 1; --i)
    {
        to[j] = from[i];
        ++j;
    }
    to[j] = '\n';
    to[++j] = '\0';
}
