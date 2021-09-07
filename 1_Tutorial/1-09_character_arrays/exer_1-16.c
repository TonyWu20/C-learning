#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /*current input line*/
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    int c;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (line[len - 1] !=
            '\n') /* When len = MAXLINE, but the last char is not '\n', the next
                     result of my_getline succeeds this result */
            while ((c = getchar()) != EOF && c != '\n')
                ++len;
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
    {
        if (max > 0)
        {
            printf("%s\n", longest);
            printf("len = %d\n", max);
        }
    }
    printf("\n");
    return 0;
}
/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
