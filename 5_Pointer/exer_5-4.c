/* Write the function strend(s,t), which returns 1 if the string t occurs at the
 * end of the string s, and zero otherwise. */
#include <stddef.h>
#include <stdio.h>

int strend(char *s, char *t);
int strend2(char *s, char *t);

int main(void)
{
    char s1[] = "Write the function strend(s,t), which returns 1 if the string "
                "t occurs at the end of the string s, and zero otherwise.";
    char *test[] = {"",          "rwise.",    "rise.",  "zero.", "rwise",
                    "therwise.", "otherwise", "123465", "\0"};
    size_t numtest = sizeof(test) / sizeof(test[0]);
    size_t testitem;
    printf("Original string: \"%s\"\n\n", s1);
    for (testitem = 1; testitem < numtest; testitem++)
    {
        printf("String \"%s\" occurs at the end?: %d (1 = yes, 0 = no)\n",
               test[testitem], strend2(s1, test[testitem]));
    }
}

int strend(char *s, char *t)
{
    char *temp = t;
    while (*s)
        ++s;
    while (*t)
        ++t;
    for (; *s == *t && t > temp; s--, t--)
        ;
    printf("s at %c, t at %c\t", *s, *t);
    if (temp == t && *s == *t)
        return 1;
    else
        return 0;
}

int strend2(char *s, char *t)
{
    char *temp = t;
    for (; *s != '\0'; ++s)
    {
        if (*temp != '\0' && *s == *temp)
            ++temp;
        else
            temp = t;
    }
    if (*s == '\0' && *temp == '\0')
        return 1;
    return 0;
}
