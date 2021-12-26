#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reversedList(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;
    struct ListNode *newHead = reversedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
