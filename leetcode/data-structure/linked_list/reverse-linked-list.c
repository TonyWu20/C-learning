/** Given the head of a singly linked list, reverse the list, and return the
 *  reversed list.
 */
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/* Iterative */

struct ListNode *reverseList(struct ListNode *head)
{
    if (!head)
        return NULL;
    struct ListNode *cur, *prev;
    prev = NULL;
    while (head != NULL)
    {
        cur = head;
        head = head->next;
        cur->next = prev;
        prev = cur;
    }
    return cur;
}

/* recursive */
struct ListNode *revListRecur(struct ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;
    struct ListNode *newHead = revListRecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
