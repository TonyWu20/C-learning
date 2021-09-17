#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int index;

    while (my_getline(line, MAXLINE) > 0)
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("%s\n", line);
            printf("Rightmost occurence of %s at: %d\n", pattern, index);
            found++;
        }
    return found;
}

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* find the rightmost occurence of t */
int strindex(char s[], char t[])
{
    int i, j, k;
    int pos = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0' && k > 0)
            pos = i;
    }
    return pos;
}
