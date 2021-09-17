#include <stdio.h>

void escape(char s[], char t[]);

int main(void)
{
    char testText[] = "\aHello, \n\tWorld! Mitake\b was \"Loss of 's'\"!\n";
    char emptyText[100];
    printf("Original string:%s\n", testText);
    escape(testText, emptyText);
    printf("Escaped display:%s\n", emptyText);
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i - j] != '\0'; ++i)
    {
        switch (s[i - j])
        {
        case '\n':
            t[i] = '\\';
            t[++i] = 'n';
            ++j;
            break;
        case '\t':
            t[i] = '\\';
            t[++i] = 't';
            ++j;
            break;
        case '\a':
            t[i] = '\\';
            t[++i] = 'a';
            ++j;
            break;
        case '\b':
            t[i] = '\\';
            t[++i] = 'b';
            ++j;
        default:
            t[i] = s[i - j];
            break;
        }
    }
    t[i] = '\0';
}
