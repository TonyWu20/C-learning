#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MINIMUM 80   /* at least 80 characters to be printed */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print all input lines that are longer than 80 characters */
int main()
{
    int clen;             /* current line length */
    char cline[MAXLINE];  /* current input line */
    char longer[MAXLINE]; /* line longer than 80 characters */
    while ((clen = my_getline(cline, MAXLINE)) > 0)
        if (clen > MINIMUM)
        {
            /*copy(longer, cline);*/
            printf("%s\n", cline);
        }
    return 0;
}
int my_getline(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = EOF;
    return i;
}
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != EOF)
        ++i;
}
