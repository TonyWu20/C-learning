#include <stdio.h>
#include <stdlib.h>
#define PRIME 1921
struct hashNode
{
    int sum;
    int count;
    struct hashNode *link;
};

int hash(int val)
{
    return abs(val % PRIME);
}

struct hashNode **initTable()
{
    struct hashNode **table = calloc(PRIME, sizeof(struct hashNode *));
    return table;
}

struct hashNode *lookup(int sum, struct hashNode *hashtab[])
{
    struct hashNode *np;
    for (np = hashtab[hash(sum)]; np != NULL; np = np->link)
    {
        if (np->sum == sum)
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
        np->sum = val;
        hashtab[hashVal] = np;
    }
    else
    {
        np->count++;
    }
    return np;
}

int subarraySum(int *nums, int numsSize, int k)
{
    struct hashNode **table = initTable();
    int sum = 0, count = 0;
    install(sum, table);
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        struct hashNode *tg = lookup(sum - k, table);
        if (tg)
            count += tg->count;
        install(sum, table);
    }
    return count;
}
