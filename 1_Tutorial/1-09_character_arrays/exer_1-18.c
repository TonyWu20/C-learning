#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, head, tail, inn;
    char line[MAXLINE];
    while ((len = my_getline(line, MAXLINE + 1)) > 0)
    {
        for (head = 0; line[head] == ' ' || line[head] == '\t'; head++)
            ;
        for (tail = len; line[tail] == ' ' || line[tail] == '\n' ||
                         line[tail] == '\t' || line[tail] == '\0';
             tail--)
            ;
        if (tail - head >= 0)
        {
            for (inn = head; inn <= tail; inn++)
                putchar(line[inn]);
            putchar('\n');
            putchar('\0');
        }
    }
    return 0;
}
/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
