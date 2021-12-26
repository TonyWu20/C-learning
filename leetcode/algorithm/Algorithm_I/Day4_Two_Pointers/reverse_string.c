void reverseString(char *s, int sSize)
{
    for (int left = 0, right = sSize - 1; left < sSize / 2; left++, right--)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
    }
}
