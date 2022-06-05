#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getMid(struct ListNode *head);
struct ListNode *reverseList(struct ListNode *);
void merge(struct ListNode *, struct ListNode *);

void reorderList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    struct ListNode *mid = getMid(head);
    struct ListNode *second_half = mid->next;
    mid->next = NULL;
    second_half = reverseList(second_half);
    merge(head, second_half);
}

struct ListNode *getMid(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *tail = NULL;
    while (head)
    {
        struct ListNode *cur = head;
        head = head->next;
        cur->next = tail;
        tail = cur;
    }
    return tail;
}

void merge(struct ListNode *head1, struct ListNode *head2)
{
    struct ListNode *head = head1;
    while (head2)
    {
        struct ListNode *next = head2->next;
        head2->next = head->next;
        head->next = head2;
        head = head->next->next;
        head2 = next;
    }
}
