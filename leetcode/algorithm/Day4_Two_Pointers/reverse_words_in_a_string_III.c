#include <stdio.h>
void revSingleWord(char *s, int start, int sSize)
{
    char tmp;
    for (int left = start, right = sSize + start - 1; left < right;
         left++, right--)
    {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
    }
}

char *reverseWords(char *s)
{
    int wordSize = 0;
    int ptr = 0;
    int start = 0;
    while (s[ptr] != '\0')
    {
        if (s[ptr] == ' ')
        {
            revSingleWord(s, start, wordSize);
            wordSize = 0;
            start = ++ptr;
            printf("%d\n", start);
        }
        else
        {
            wordSize++;
            ptr++;
        }
    }
    revSingleWord(s, start, wordSize);
    return s;
}

int main(int argc, char *argv[])
{
    char s[] = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(s));
    return 0;
}
