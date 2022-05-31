#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *res = calloc(1, sizeof(struct ListNode));
    res->next = head;
    struct ListNode *pred = res;
    struct ListNode *cur = head;
    while (cur)
    {
        if (cur->next && cur->val == cur->next->val)
        {
            while (cur->next && cur->val == cur->next->val)
                cur = cur->next;
            pred->next = cur->next;
        }
        else
        {
            pred = pred->next;
        }
        cur = cur->next;
    }
    return res->next;
}
