#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();

typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
};

struct DoublyLinkedList
{
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
};

DoublyLinkedListNode *create_doubly_linked_list_node(int node_data)
{
    DoublyLinkedListNode *node = malloc(sizeof(DoublyLinkedListNode));

    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insert_node_into_doubly_linked_list(DoublyLinkedList **doubly_linked_list,
                                         int node_data)
{
    DoublyLinkedListNode *node = create_doubly_linked_list_node(node_data);

    if (!(*doubly_linked_list)->head)
    {
        (*doubly_linked_list)->head = node;
    }
    else
    {
        (*doubly_linked_list)->tail->next = node;
        node->prev = (*doubly_linked_list)->tail;
    }

    (*doubly_linked_list)->tail = node;
}

void print_doubly_linked_list(DoublyLinkedListNode *node, char *sep, FILE *fptr)
{
    while (node)
    {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node)
        {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
    while (node)
    {
        DoublyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *head = llist;
    if (!head)
    {
        head = malloc(sizeof(DoublyLinkedListNode));
        head->data = data;
        head->next = head->prev = NULL;
        return head;
    }
    while (head)
    {
        if (head->data < data)
        {
            if (head->next)
                head = head->next;
            else
            {
                DoublyLinkedListNode *ins = malloc(sizeof(*ins));
                ins->data = data;
                ins->next = NULL;
                head->next = ins;
                ins->prev = head;
            }
        }
        else if (head != llist) // not in the beginning
        {
            DoublyLinkedListNode *ins = malloc(sizeof(*ins));
            ins->data = data;
            ins->next = head;
            head->prev->next = ins;
            ins->prev = head->prev;
        }
        else // in the beginning
        {
            DoublyLinkedListNode *ins = malloc(sizeof(*ins));
            ins->data = data;
            ins->next = head;
            head->prev = ins;
            ins->prev = NULL;
        }
    }
    return llist;
}
