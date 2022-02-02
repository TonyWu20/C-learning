#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *tmp;
    tmp = malloc(sizeof(struct ListNode));
    tmp->val = 0;
    tmp->next = NULL;
    struct ListNode *curr = tmp;
    int remainder = 0, sum;
    while (l1 || l2 || remainder)
    {
        sum =
            remainder + (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
        remainder = sum / 10;
        sum %= 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->next = NULL;
        curr->next->val = sum;
        curr = curr->next;
        l1 = (!l1) ? NULL : l1->next;
        l2 = (!l2) ? NULL : l2->next;
    }
    return tmp->next;
}
