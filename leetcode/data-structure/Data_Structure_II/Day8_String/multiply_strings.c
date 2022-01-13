#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strRev(char *s)
{
    int sLen = strlen(s);
    char *rev = malloc(sizeof(char) * (sLen + 1));
    for (int i = sLen - 1, j = 0; i >= 0; --i, ++j)
    {
        rev[j] = s[i];
    }
    rev[sLen] = 0;
    return rev;
}

char *multiply(char *num1, char *num2)
{
    if (*num1 == '0' || *num2 == '0')
        return "0";
    int n1Len = strlen(num1);
    int n2Len = strlen(num2);
    int retLen = n1Len + n2Len;
    char *res = calloc(retLen + 1, sizeof(int));
    for (int i = 0; i < retLen; ++i)
    {
        res[i] = '0' + 0;
    }
    char *revNum1 = strRev(num1);
    char *revNum2 = strRev(num2);
    int lastDigit, carry, currPos, multi;
    carry = 0;
    for (int i = 0; i < n2Len; ++i)
    {
        for (int j = 0; j < n1Len; ++j)
        {
            currPos = i + j;
            multi =
                (revNum1[j] - '0') * (revNum2[i] - '0') + (res[currPos] - '0');
            lastDigit = multi % 10;
            res[currPos] = lastDigit + '0';
            carry = multi / 10;
            res[currPos + 1] += carry;
        }
    }
    if (res[currPos + 1] == '0')
        res[currPos + 1] = 0;
    char *ans = strRev(res);
    free(res);
    free(revNum1);
    free(revNum2);
    return ans;
}

int main(int argc, char *argv[])
{
    char num1[] = "123", num2[] = "456";
    printf("%s\n", multiply(num1, num2));
    return 0;
}
