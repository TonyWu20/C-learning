typedef enum
{
    false,
    true
} bool;

bool canConstruct(char *ransomNote, char *magazine)
{
    int alphaMap[26] = {0};
    for (int i = 0; magazine[i] != '\0'; ++i)
    {
        alphaMap[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; ++i)
    {
        if (--alphaMap[ransomNote[i] - 'a'] < 0)
            return false;
    }
    return true;
}
