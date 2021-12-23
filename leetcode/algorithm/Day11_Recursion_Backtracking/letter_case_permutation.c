#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char *s, int *returnSize, char **output, int start, int end)
{
    if (start == end)
    {
        (*returnSize)++;
        output[*returnSize - 1] = strdup(s);
        return;
    }
    char c = s[start];
    if (c >= '0' && c <= '9')
    {
        search(s, returnSize, output, start + 1, end);
    }
    s[start] = tolower(c);
    search(s, returnSize, output, start + 1, end);
    s[start] = toupper(c);
    search(s, returnSize, output, start + 1, end);
}
char **letterCasePermutation(char *s, int *returnSize)
{
    int len = strlen(s);
    *returnSize = 1;
    for (int i = 0; i < len; ++i)
    {
        if (isalpha(s[i]))
            *returnSize *= 2; // 2^n cases for n letters
    }
    char **output = malloc(sizeof(char *) * (*returnSize));
    *returnSize = 0;
    search(s, returnSize, output, 0, len);
    return output;
}

int main()
{
    char s[] = "C";
    int returnSize;
    char **result = letterCasePermutation(s, &returnSize);
    for (int i = 0; i < returnSize; ++i)
    {
        printf("%s\n", result[i]);
    }
}
