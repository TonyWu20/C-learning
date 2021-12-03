
int firstUniqChar(char *s)
{
    int countMap[26] = {0};
    char *c = s;
    while (*c != '\0')
    {
        countMap[*c - 'a']++;
        c++;
    }
    c = s;
    while (*c != '\0')
    {
        if (countMap[*c - 'a'] == 1)
            return c - s;
        c++;
    }
    return -1;
}
