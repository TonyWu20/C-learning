#include <stdio.h>

void mystrcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
void pstrcat(char *s, char *t)
{
    while (*s)
        s++;
    while ((*s++ = *t++) != '\0')
        ;
}
void pstrcpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}
int main(void)
{
    char s1[] = "Hello ";
    char s2[] = "World!";
    char buffer[128];
    pstrcpy(buffer, s1);
    pstrcat(buffer, s2);
    printf("String 1:%s, String 2:%s, Concatenated: %s\n", s1, s2, buffer);
    return 0;
}
