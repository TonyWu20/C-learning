#include <stdint.h>
#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;
    struct ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
