#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (!head)
        return NULL;
    struct ListNode *curr, *prev, *next;
    curr = head;
    prev = next = NULL;
    int i = 0, length = 0;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL && i < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    length -= i;                     // remaining length
    if (next != NULL && length >= k) // if length > k continue to reverse
        head->next = reverseKGroup(next, k);
    else
        head->next = next;
    return prev;
}
