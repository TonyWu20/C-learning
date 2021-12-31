/**Algorithm
 *
 * For each letter, say it occurs v times. We know we have v // 2 * 2 letters
 * that can be partnered for sure. For example, if we have 'aaaaa', then we
 * could have 'aaaa' partnered, which is 5 // 2 * 2 = 4 letters partnered.
 *
 * At the end, if there was any v % 2 == 1, then that letter could have been a
 * unique center. Otherwise, every letter was partnered. To perform this check,
 * we will check for v % 2 == 1 and ans % 2 == 0, the latter meaning we haven't
 * yet added a unique center to the answer.
 */
int longestPalindrome(char *s)
{
    int count[128] = {0};
    char *c = s;
    while (*c != '\0')
    {
        count[(int)*c]++;
        c++;
    }
    int ans = 0;
    for (int i = 0; i < 128; ++i)
    {
        int v = count[i];
        ans += v / 2 * 2;
        if (ans % 2 == 0 && v % 2 == 1)
            ans += 1;
    }
    return ans;
}
