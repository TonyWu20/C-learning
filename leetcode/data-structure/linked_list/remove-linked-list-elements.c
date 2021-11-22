/** Given the head of a linked list and an integer val, remove all the nodes of
 *  the linked list that has Node.val == val, and return the new head.
 */
#include <stdio.h>

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
        /* Keep the current node, recursion to next node */
        head->next = removeElements(head->next, val);
    }
    else
    {
        /* Replace the current node to the next result of the recursion */
        return removeElements(head->next, val);
    }
    return head; /* recursion */
}
