#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double */
double atof(char string[]);
double atofSci(char string[]);

int main(void)
{
    char number1[] = "123.45";
    char number2[] = "123.41e6";
    char number3[] = "123.45e-6";
    printf("Original atof: %s -> %.2f\n", number1, atof(number1));
    printf("atofSci: %s -> %.6f\n", number2, atofSci(number2));
    printf("atofSci: %s -> %.12f\n", number3, atofSci(number3));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val +
              (s[i] - '0'); /* from left to right, assemble subsequent number by
                               multiplying 10 of the read component */
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

double atofSci(char s[])
{
    double val, power, epower;
    int i, sign;
    int esign, exp;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-')
        i++;
    for (exp = 0; isdigit(s[i]); i++)
    {
        exp = 10 * exp + (s[i] - '0');
    }
    for (i = 0, epower = 1.0; i < exp; i++)
    {
        if (esign == -1)
        {
            epower /= 10.0;
        }
        else if (esign == 1)
        {
            epower *= 10.0;
        }
    }
    return sign * val / power * epower;
}
