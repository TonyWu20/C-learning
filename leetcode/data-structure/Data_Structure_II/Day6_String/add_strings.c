#include <stdlib.h>
#include <string.h>

char *addStrings(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len3 = (len1 > len2) ? len1 : len2;
    int size3;
    if (len1 == len2 && (num1[0] + num2[0] > '0' + '0' + 9))
        len3++;
    size3 = len3 + 1;
    char *num3 = malloc((size3) * sizeof(char));
    int digit, carry;
    carry = 0;
    while (len1 != 0 || len2 != 0)
    {
        digit = ((!len1) ? 0 : num1[--len1] - '0') +
                ((!len2) ? 0 : num2[--len2] - '0');
        if (carry)
            ++digit;
        carry = digit / 10;
        if (carry)
            digit = (digit % 10);
        num3[--len3] = '0' + digit;
    }
    if (carry)
    {
        if (len3 == 0)
        {
            num3 = realloc(num3, ++size3);
            memmove(num3 + 1, num3, (size3 - 2) * sizeof(char));
        }
        num3[0] = '1';
    }
    num3[size3 - 1] = '\0';
    return num3;
}
