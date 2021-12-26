#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;
typedef struct
{
    int size;
    int current;
    int *queue;
} MyQueue;
bool myQueueEmpty(MyQueue *obj);

MyQueue *myQueueCreate()
{
    MyQueue *ret = malloc(sizeof(MyQueue));
    if (!ret)
    {
        printf("Error when malloc memory\n");
        return NULL;
    }
    ret->size = 10;
    ret->current = -1;
    ret->queue = malloc(sizeof(int) * 10);
    return ret;
}

// Push x to back of the queue
void myQueuePush(MyQueue *obj, int x)
{
    obj->current++;
    if (obj->current >= obj->size)
    {
        int *new = malloc(sizeof(int) * 2 * obj->size);
        memcpy(new, obj->queue, sizeof(int) * obj->size);
        free(obj->queue);
        obj->queue = new;
        obj->size *= 2;
    }
    obj->queue[obj->current] = x;
}

int myQueuePop(MyQueue *obj)
{
    int popped = obj->queue[0];
    for (int i = 0; i < obj->current; ++i)
    {
        obj->queue[i] = obj->queue[i + 1];
    }
    obj->current--;
    return popped;
}

int myQueuePeek(MyQueue *obj)
{
    if (myQueueEmpty(obj) == false)
    {
        int elm = obj->queue[obj->current];
        return elm;
    }
    printf("No element in queue yet.\n");
    return -1;
}

bool myQueueEmpty(MyQueue *obj)
{
    if (obj->current >= 0)
        return false;
    else
        return true;
}

void myQueueFree(MyQueue *obj)
{
    if (obj->queue)
        free(obj->queue);
    free(obj);
}
