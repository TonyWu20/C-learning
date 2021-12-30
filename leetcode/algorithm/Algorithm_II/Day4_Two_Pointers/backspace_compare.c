#include <string.h>
typedef enum
{
    false,
    true
} bool;

bool backspaceCompare(char *s, char *t)
{
    int sPtr = strlen(s) - 1, tPtr = strlen(t) - 1;
    int skipS = 0, skipT = 0;
    while (sPtr >= 0 || tPtr >= 0)
    {
        while (sPtr >= 0)
        {
            if (s[sPtr] == '#')
            {
                skipS++;
                sPtr--;
            }
            else if (skipS > 0)
            {
                skipS--;
                sPtr--;
            }
            else
                break;
        }
        while (tPtr >= 0)
        {
            if (t[tPtr] == '#')
            {
                tPtr--;
                skipT++;
            }
            else if (skipT > 0)
            {
                skipT--;
                tPtr--;
            }
            else
                break;
        }
        if (sPtr >= 0 && tPtr >= 0 && s[sPtr] != t[tPtr])
            return false;
        if ((sPtr >= 0) != (tPtr >= 0))
            return false;
        sPtr--;
        tPtr--;
    }
    return true;
}
