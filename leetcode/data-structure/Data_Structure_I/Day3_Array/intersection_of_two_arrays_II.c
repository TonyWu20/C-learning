#include <stdio.h>
#include <stdlib.h>
#define PRIME 1921

struct hashNode
{
    int val;
    int count;
    struct hashNode *link;
};

int hash(int val)
{
    return abs(val % PRIME);
}

struct hashNode *lookup(int val, struct hashNode *hashtab[])
{
    struct hashNode *np;
    for (np = hashtab[hash(val)]; np != NULL; np = np->link)
    {
        if (np->val == val)
            return np;
    }
    return NULL;
}

void freeTable(struct hashNode *hashtab[])
{
    struct hashNode *np;
    for (int i = 0; i < PRIME; ++i)
    {
        np = hashtab[i];
        if (np != NULL)
        {
            struct hashNode *link;
            link = np->link;
            while (link)
            {
                struct hashNode *next;
                next = link->link;
                free(link);
                link = next;
            }
            free(np);
        }
    }
}

struct hashNode *install(int val, struct hashNode *hashtab[])
{
    struct hashNode *np;
    int hashVal;

    if ((np = lookup(val, hashtab)) == NULL)
    {
        np = malloc(sizeof(*np));
        if (np == NULL)
            return NULL;
        hashVal = hash(val);
        np->link = hashtab[hashVal]; /* push the original node to link */
        np->count = 1;
        np->val = val;
        hashtab[hashVal] = np;
    }
    else
    {
        np->count++;
    }
    return np;
}
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
    struct hashNode *hashtab[PRIME] = {NULL};
    int checkSize, lookupSize;
    *returnSize = 0;
    int *ret = malloc(sizeof(int));
    if (nums1Size > nums2Size)
    {
        checkSize = nums2Size;
        lookupSize = nums1Size;
        for (int i = 0; i < checkSize; ++i)
        {
            struct hashNode *node;
            node = install(nums2[i], hashtab);
            if (node == NULL)
                return NULL;
        }
        for (int i = 0; i < lookupSize; ++i)
        {
            struct hashNode *node;
            node = lookup(nums1[i], hashtab);
            if (node && node->count > 0)
            {
                *returnSize += 1;
                node->count--;
                ret = realloc(ret, sizeof(int) * (*returnSize));
                ret[*returnSize - 1] = nums1[i];
            }
        }
    }
    else
    {
        checkSize = nums1Size;
        lookupSize = nums2Size;
        for (int i = 0; i < checkSize; ++i)
        {
            struct hashNode *node;
            node = install(nums1[i], hashtab);
            if (node == NULL)
                return NULL;
        }
        for (int i = 0; i < lookupSize; ++i)
        {
            struct hashNode *node;
            node = lookup(nums2[i], hashtab);
            if (node && node->count > 0)
            {
                *returnSize += 1;
                node->count--;
                ret = realloc(ret, sizeof(int) * (*returnSize));
                ret[*returnSize - 1] = nums2[i];
            }
        }
    }
    freeTable(hashtab);
    return ret;
}

int main(int argc, char *argv[])
{
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2[] = {2, 2};
    int nums2Size = sizeof(nums2) / sizeof(int);
    int returnSize = 0;
    int *ret = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);
    if (ret)
    {
        printf("[");
        for (int i = 0; i < returnSize; ++i)
        {
            printf("%d%s", ret[i], (i == returnSize - 1) ? "]\n" : ",");
        }
    }
    free(ret);
    return 0;
}
