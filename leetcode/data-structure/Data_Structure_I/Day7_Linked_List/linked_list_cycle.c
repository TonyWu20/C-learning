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

// let fast moves one step faster than slow in each loop, so eventually they
// will overlap if a cycle exists
bool hasCycle(struct ListNode *head)
{
    if (head) // exclude the empty list
    {
        struct ListNode *fast = head->next;
        struct ListNode *slow = head;
        while (fast && fast != slow)
        {
            if (fast->next && fast->next->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                return false;
            }
        }

        if (fast == slow) // if while loop terminates by fast==slow
            return true;
        else // or if the fast is NULL
            return false;
    }
    return false;
}
