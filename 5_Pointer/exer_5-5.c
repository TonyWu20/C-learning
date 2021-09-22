#include <stdio.h>

void my_strcpy(char *s, char *t);
void my_strcat(char *s, char *t);
int my_strcmp(char *s, char *t);

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

void my_strcpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}
void my_strncpy(char *s, char *t, int n)
{
    while (n-- > 0)
        *s++ = *t++;
}
void my_strcat(char *s, char *t)
{
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}
void my_strncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    while (n-- > 0)
        *s++ = *t++;
}
int my_strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
int my_strncmp(char *s, char *t, int n)
{
    char *pt;
    pt = t;
    for (; *s == *t; s++, t++)
    {
        if ((t - pt) == n - 1)
            return 0;
    }
    return *s - *t;
}
int main(void)
{
    char s1[] = "Hello ";
    char s2[] = "World!";
    char s3[] = "Hallo ";
    char buffer[128];
    int i;
    i = 5;
    my_strncpy(buffer, s1, i);
    printf("%s copied from %s at most %d characters\n", buffer, s1, i);
    i = 4;
    my_strncat(buffer, s2, i);
    printf("%s concat with %s at most %d characters\n", buffer, s2, i);

    printf("%s compared with %s at most %d characters: %d\n", buffer, s3, i,
           my_strncmp(buffer, s3, i));
    i = 1;
    printf("%s compared with %s at most %d characters: %d\n", buffer, s3, i,
           my_strncmp(buffer, s3, i));
    return 0;
}
