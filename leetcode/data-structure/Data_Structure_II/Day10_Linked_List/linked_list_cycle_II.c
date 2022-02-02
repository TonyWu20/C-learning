#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

// let fast moves one step faster than slow in each loop, so eventually they
// will overlap if a cycle exists
struct ListNode *detectCycle(struct ListNode *head)
{
    if (head && head->next) // exclude the empty list
    {
        struct ListNode *fast = head;
        struct ListNode *slow = head;
        slow = slow->next;
        fast = fast->next->next;
        while (fast && fast->next)
        {
            if (slow == fast)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != fast)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}
