#include <stdio.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

bool isValid(char *s)
{
    int length = strlen(s);
    char stack[length];
    int top = -1;
    char c;
    while ((c = *s) != '\0')
    {
        switch (c)
        {
        case (')'):
            if (top == -1 || stack[top--] != '(')
            {
                return false;
            }
            break;
        case ('}'):
            if (top == -1 || stack[top--] != '{')
            {
                return false;
            }
            break;
        case (']'):
            if (top == -1 || stack[top--] != '[')
            {
                return false;
            }
            break;
        default:
            stack[++top] = c;
            break;
        }
        s++;
    }
    return top == -1;
}

int main(int argc, char *argv[])
{
    char *s[] = {"()", "()[]{}", "(]", "([)]", "{[]}", "("};
    for (int i = 0; i < (sizeof(s) / sizeof(char *)); ++i)
    {
        printf("%s: %s\n", s[i], (isValid(s[i]) == true) ? "true" : "false");
    }
    return 0;
}
