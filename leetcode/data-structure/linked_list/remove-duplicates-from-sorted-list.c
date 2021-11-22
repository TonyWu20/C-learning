/** Given the head of a sorted linked list, delete all duplicates such that each
 * element appears only once. Return the linked list sorted as well.
 */

/* This is similar to remove-linked-list-elements */
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;
    if (head->next->val == head->val)
        return deleteDuplicates(head->next);
    else
        head->next = deleteDuplicates(head->next);
    return head;
}
