#include <assert.h>
#include <stdlib.h>

typedef struct MyLinkedList MyLinkedList;
struct MyLinkedList
{
    int length;
    int val;
    MyLinkedList *next;
};

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->val = -1;
    obj->next = NULL;
    obj->length = -1;
    return obj;
}
/** Get the value of the indexth node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < -1 || index > obj->length)
        return -1;
    obj = obj->next;
    int i = 0;
    while (i != index)
    {
        obj = obj->next;
        i++;
    }
    return obj->val;
}
/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *new = malloc(sizeof(MyLinkedList));
    obj->length++;
    new->next = obj->next;
    new->val = val;
    obj = new;
}
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    while (obj->next != NULL)
    {
        obj = obj->next;
    }
    // at tail
    MyLinkedList *new_tail = malloc(sizeof(MyLinkedList));
    new_tail->val = val;
    new_tail->next = NULL;
    obj->next = new_tail;
    obj->length++;
}
/** Add a node of value val before the indexth node in the linked list. If index
 * equals the length of the linked list, the node will be appended to the end of
 * the linked list. If index is greater than the length, the node will not be
 * inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (obj->length + 1 < index || index < -1)
        return;
    int i = 0;
    while (i != index)
    {
        obj = obj->next;
        i++;
    }
    // Come to the insert position.
    MyLinkedList *new_ins = malloc(sizeof(MyLinkedList));
    obj->length++;
    new_ins->val = val;
    new_ins->next = obj->next;
    obj->next = new_ins;
}
/** Delete the indexth node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (obj->length < index || index < -1)
        return;
    int i = 0;
    while (i != index)
    {
        obj = obj->next;
        i++;
    }
    MyLinkedList *rm = obj->next;
    obj->next = rm->next;
    free(rm);
    obj->length--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    while (obj != NULL)
    {
        MyLinkedList *tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
