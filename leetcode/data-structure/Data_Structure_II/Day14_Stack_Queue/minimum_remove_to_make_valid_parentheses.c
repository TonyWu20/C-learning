#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 100000 // String size max limit given from question
char *minRemoveToMakeValid(char *s)
{
    int stack[STACK_MAX_SIZE] = {-1}; // initiate a stack for storing
                                      // parentheses' indexes
    int stackTop = 0;
    for (int i = 0; s[i] != '\0'; i++) // Go through the string
    {
        switch (s[i])
        {
        case '(': // Push '(' whenever
            stack[stackTop++] = i;
            break;
        case ')':
            // StackTop == 0: The first parenthesis is the ')'
            // s[stack[stackTop - 1]] != '(': The ')' does not form a pair with
            // the latest recorded parenthesis.
            if (stackTop == 0 || s[stack[stackTop - 1]] != '(')
                stack[stackTop++] = i;
            else // The last recorded one is '(', forming a valid pair.
            {
                stack[--stackTop] = -1; // Pop the stack top
            }
            break;
        default: // Letter
            break;
        }
    }
    int stack_p = 0,
        write_p =
            0; // Initiate two pointers for checking stack and writing position.
    for (int i = 0; s[i] != '\0'; i++)
    {
        // Compare the current index with the stack record.
        // Popped data is -1 so it will never cause extra skipping for i
        if (i == stack[stack_p])
        {
            stack_p++;
            continue;
        }
        s[write_p] = s[i];
        write_p++;
    }
    s[write_p] = '\0';
    return s;
}
