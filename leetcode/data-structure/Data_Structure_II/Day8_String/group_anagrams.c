#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *key;
    char *val;
};

int cmpp(const void *a, const void *b)
{
    struct node *x = (struct node *)a;
    struct node *y = (struct node *)b;
    return strcmp(x->key, y->key);
}

int cmpc(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

void addString(char ***ans, int *row, int *col, char **pre, char *toChk,
               char *toAdd)
{
    if (!(*pre) || strcmp(*pre, toChk))
    {
        col[(*row)] = 1;
        ans[(*row)] = realloc(ans[(*row)], sizeof(char *) * col[(*row)]);
        ans[(*row)][0] = toAdd;
        (*row)++;
    }
    else
    {
        col[(*row) - 1]++;
        ans[(*row) - 1] =
            realloc(ans[(*row) - 1], sizeof(char *) * col[(*row) - 1]);
        ans[(*row) - 1][col[(*row) - 1] - 1] = toAdd;
    }
    *pre = toChk;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize,
                      int **returnColumnSizes)
{
    struct node *pairs = calloc(strsSize, sizeof(struct node));
    int i;
    char *pre = NULL;
    char ***ans = calloc(strsSize, sizeof(char **));
    *returnSize = 0;
    *returnColumnSizes = calloc(strsSize, sizeof(int));
    for (i = 0; i < strsSize; ++i)
    {
        pairs[i].val = strs[i];
        pairs[i].key = strdup(strs[i]);
        qsort(pairs[i].key, strlen(pairs[i].key), sizeof(char), cmpc);
    }
    qsort(pairs, strsSize, sizeof(struct node), cmpp);
    for (i = 0; i < strsSize; i++)
    {
        addString(ans, returnSize, *returnColumnSizes, &pre, pairs[i].key,
                  pairs[i].val);
    }
    return ans;
}
