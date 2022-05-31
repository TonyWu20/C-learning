#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB)
{
    if (!headA || !headB)
        return NULL; // Either one listnode is null
    int sizeA = 0, sizeB = 0;
    struct ListNode *currA = headA; // Two pointers
    struct ListNode *currB = headB; // to go through the lists
    // Go through List A to get size
    while (currA)
    {
        sizeA++;
        currA = currA->next;
    }
    // Go through List B to get size
    while (currB)
    {
        sizeB++;
        currB = currB->next;
    }
    currA = headA; // reset to head
    currB = headB; // reset to head
    // March the longer one to get to the same starting point
    if (sizeA < sizeB)
    {
        int diff = sizeB - sizeA;
        for (int i = 0; i < diff; i++)
            currB = currB->next;
    }
    else
    {
        int diff = sizeA - sizeB;
        for (int i = 0; i < diff; i++)
            currA = currA->next;
    }
    while (currA) // Find the intersection node
    {
        if (currA == currB)
            return currA;
        else
        {
            currA = currA->next;
            currB = currB->next;
        }
    }
    return NULL;
}
