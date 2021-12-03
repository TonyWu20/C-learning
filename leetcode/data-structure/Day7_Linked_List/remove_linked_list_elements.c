#include <stdio.h>
typedef enum
{
    false,
    true
} bool;

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (!head)
        return NULL;
    if (head->val != val)
    {
        head->next = removeElements(head->next, val);
        return head;
    }
    else
    {
        return removeElements(head->next, val);
    }
}
