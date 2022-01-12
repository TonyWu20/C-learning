#include <stdio.h>
#include <stdlib.h>

int *partitionLabels(char *s, int *returnSize)
{
    int last[26] = {0};
    for (int i = 0; s[i] != '\0'; ++i)
    {
        last[s[i] - 'a'] = i;
    }
    int start, anchor;
    start = anchor = 0;
    *returnSize = 0;
    int *ans = NULL;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        anchor = (anchor > last[s[i] - 'a']) ? anchor : last[s[i] - 'a'];
        if (i == anchor)
        {
            (*returnSize)++;
            ans = realloc(ans, sizeof(int) * (*returnSize));
            ans[*returnSize - 1] = i - start + 1;
            start = i + 1;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    char s[] = "ababcbacadefegdehijhklij";
    int returnSize;
    int *ans = partitionLabels((char *)s, &returnSize);
    for (int i = 0; i < returnSize; ++i)
    {
        printf("%d\n", ans[i]);
    }
    free(ans);
    return 0;
}
