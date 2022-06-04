#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Design a stack that supports push, pop, top and retrieving the minimum
 * element in constant time. */

typedef struct
{
    int top;
    int min_count;
    int stack[8000]; // Based on testcases in Leetcode
    int min[30];     // 20 will report heap overflow in leetcode submission
} MinStack;

MinStack *minStackCreate()
{
    MinStack *obj = malloc(sizeof(MinStack));
    obj->top = -1;
    obj->min_count = 0;
    return obj;
}

void minStackPush(MinStack *obj, int val)
{
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->min_count == 0 || val <= obj->min[obj->min_count - 1])
    {
        obj->min[obj->min_count++] = val;
    }
}

void minStackPop(MinStack *obj)
{
    if (obj->top == -1)
        return;
    if (obj->min_count == 0)
        ;
    else if (obj->stack[obj->top] == obj->min[obj->min_count - 1])
        obj->min_count--;
    obj->top--;
}

int minStackTop(MinStack *obj)
{
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    return obj->min[obj->min_count - 1];
}

void minStackFree(MinStack *obj)
{
    free(obj);
}
