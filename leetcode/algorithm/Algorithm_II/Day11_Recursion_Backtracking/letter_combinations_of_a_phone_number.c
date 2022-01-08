#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combRes(char *digits, int digitsLen, char **phone, char *tmp, int start,
             int *idx, char **ans)
{
    if (start == digitsLen)
    {
        tmp[start] = 0;
        ans[(*idx)++] = strdup(tmp);
        return;
    }
    char *phoneNum = phone[digits[start] - '0'];
    for (int i = 0; i < strlen(phoneNum); ++i)
    {
        tmp[start] = phoneNum[i];
        combRes(digits, digitsLen, phone, tmp, start + 1, idx, ans);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    char *phone[] = {"",    "",    "abc",  "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **ans = malloc(sizeof(char *) * 4000);
    int digitsLen = strlen(digits);
    if (digitsLen == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    char tmp[digitsLen + 1];
    int idx = 0;
    combRes(digits, digitsLen, phone, tmp, 0, &idx, ans);
    *returnSize = idx;
    return ans;
}
