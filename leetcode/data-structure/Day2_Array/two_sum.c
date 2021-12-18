#include <stdio.h>
#include <stdlib.h>

#define PRIME 197

struct hashNode
{
    int val;
    int index;
    struct hashNode *next;
};

int hash(int val)
{
    return abs(val % PRIME);
}

struct hashNode **createHashTab()
{
    struct hashNode **tab = malloc(sizeof(struct hashNode *) * PRIME);
    for (int i = 0; i < PRIME; ++i)
    {
        tab[i] = NULL;
    }
    return tab;
}

struct hashNode *lookup(struct hashNode *tab[], int val)
{
    struct hashNode *np;
    for (np = tab[hash(val)]; np != NULL; np = np->next)
    {
        if (np->val == val)
            return np;
    }
    return NULL;
}

struct hashNode *install(struct hashNode *tab[], int val, int id)
{
    struct hashNode *np = lookup(tab, val);
    if (!np)
    {
        np = malloc(sizeof(struct hashNode));
        np->val = val;
        np->index = id;
        np->next = tab[hash(val)];
        tab[hash(val)] = np;
    }
    return np;
}

void freeHashTab(struct hashNode *tab[])
{
    for (int i = 0; i < PRIME; ++i)
    {
        struct hashNode *np = tab[i];
        if (np)
        {
            struct hashNode *link = np->next;
            while (link)
            {
                struct hashNode *next = link->next;
                free(link);
                link = next;
            }
            free(np);
        }
    }
    free(tab);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    struct hashNode **hashTab = createHashTab();
    install(hashTab, nums[0], 0);
    int *ret = malloc(sizeof(int) * 2);
    for (int i = 1; i < numsSize; ++i)
    {
        int remain = target - nums[i];
        struct hashNode *np;
        if ((np = lookup(hashTab, remain)))
        {
            ret[0] = np->index;
            ret[1] = i;
            *returnSize = 2;
            freeHashTab(hashTab);
            return ret;
        }
        else
        {
            install(hashTab, nums[i], i);
        }
    }
    *returnSize = 0;
    freeHashTab(hashTab);
    return NULL;
}
