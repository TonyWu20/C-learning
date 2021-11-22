#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool
{
    false,
    true
} bool;

bool canConstruct(char *ransomNote, char *magazine)
{
    int charMap[26] = {0};
    int magazineLength = strlen(magazine);
    for (int i = 0; i < magazineLength; ++i)
    {
        int charId = magazine[i] - 'a';
        charMap[charId]++;
    }
    int noteLength = strlen(ransomNote);
    for (int i = 0; i < noteLength; ++i)
    {
        int charId = ransomNote[i] - 'a';
        charMap[charId]--;
        if (charMap[charId] < 0)
            return false;
    }
    return true;
}
