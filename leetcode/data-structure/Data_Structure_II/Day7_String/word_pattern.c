#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;

bool wordPattern(char *pattern, char *s)
{
    int i, j, len = strlen(pattern);
    int search[len];
    char *token, *saveptr;
    char strtmp[strlen(s)];
    for (i = 0; i < len; ++i)
        search[i] = -1;
    strcpy(strtmp, s);
    token = strtok_r(strtmp, " ", &saveptr);
    for (i = 0; i < len; ++i)
    {
        int a = strchr(pattern, pattern[i]) -
                pattern;   // find index of current pattern;
        if (token == NULL) // no token back; string s ends
            break;
        int b = strstr(s, token) - s; // find starting index of the token in s;
        for (j = 0; j < a; ++j)
        {
            if (search[j] ==
                b) // check if token has been assigned to previous patterns
                return false;
        }
        if (search[a] == -1) // if the pattern has not been assigned
            search[a] = b;   // assign current starting position of the token to
                             // the pattern
        else if (search[a] != b) // Pattern assigned and not equal to token
            return false;
        token = strtok_r(NULL, " ", &saveptr); // Get next token by strtok_r
    }
    return (token == NULL) ==
           (i == len); // Check both conditions: separation by " " is over and
                       // all patterns have been checked. Either one not
                       // fulfilled is false;
}
