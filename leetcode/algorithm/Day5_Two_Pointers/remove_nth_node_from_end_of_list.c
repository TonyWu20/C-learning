#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (head->next == NULL)
        return NULL;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (n > 0 && fast->next)
    {
        fast = fast->next;
        n--;
    }
    if (n == 1)
    {
        return head->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
