#include <stdio.h>
#define MAXLINE 1000

char pattern[] = "ould"; /* pattern to search for */
int p_getline(char *s, int lim);
int p_strindex(char *s, char *t);

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int index;

    while (p_getline(line, MAXLINE) > 0)
        if ((index = p_strindex(line, pattern)) >= 0)
        {
            printf("Line: %s\n", line);
            printf("Rightmost occurence of %s at: %d\n", pattern, index);
            found++;
        }
    return found;
}
int p_getline(char *s, int lim)
{
    int c;
    char *startS = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - startS;
}
int p_strindex(char *s, char *t)
{
    char *startS = s;
    char *startT = t;
    char *tempS;
    int pos = -1;
    for (; *s != '\0'; s++)
    {
        for (tempS = s, t = startT; *t != '\0' && *tempS == *t; tempS++, t++)
            ;
        if (*t == '\0' && (t - startT) > 0)
            pos = s - startS;
    }
    return pos;
}
