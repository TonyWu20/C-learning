struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    // the fast pointer goes twice the speed of the slow pointer
    // so that the slow pointer will be in the middle when the fast
    // goes to the end.
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
