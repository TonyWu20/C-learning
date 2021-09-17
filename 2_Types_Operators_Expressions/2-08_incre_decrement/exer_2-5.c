#include <stdio.h>

int any(char s1[], char s2[]);

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s2[j] == s1[i])
            {
                return i;
            }
        }
    }
    return -1;
}

int main(void)
{
    char *s1[] = {"", "LLnad", "MacOS", "Apple", "Fox", "styles", "xlxc"};
    char s2[] = {"aeiouAEIOU"};
    int s1_size = sizeof(s1) / sizeof(s1[0]);
    /*int s2_size = sizeof(s2) / sizeof(s2[0]);*/
    int left;
    int pos;
    for (left = 0; left < s1_size; left++)
    {
        pos = any(s1[left], s2);
        if (pos != -1)
        {
            printf("String: %s, First loc %d\n", s1[left], pos);
        }

        if (pos == -1)
            printf("String: %s, No character from s2\n", s1[left]);
    }
}
