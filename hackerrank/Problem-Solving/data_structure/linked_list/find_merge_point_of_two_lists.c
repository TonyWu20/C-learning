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

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

struct SinglyLinkedList
{
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
};

SinglyLinkedListNode *create_singly_linked_list_node(int node_data)
{
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList **singly_linked_list,
                                         int node_data)
{
    SinglyLinkedListNode *node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head)
    {
        (*singly_linked_list)->head = node;
    }
    else
    {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode *node, char *sep, FILE *fptr)
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

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *ptr1 = head1, *ptr2 = head2;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == NULL)
            ptr1 = head2;
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1->data; // The question guarantees that the list will merge
}
