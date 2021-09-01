#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLENGTH 30
int vhistogram(int wordlen[], int maxlength);
int main()
{
    int i, j; /* i and j are simply index counters */
    i = j = 0;
    int c = 0;
    int nchar = 0; /* number of characters in a word */
    int inspace =
        IN; /* a flag to know whether we are inside or outside of the word */
    int wordlen[MAXLENGTH]; /* counts how many words of a particular length we
                               have seen */

    for (i = 0; i < MAXLENGTH; ++i)
        wordlen[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (inspace == OUT)
            {
                if (nchar <= MAXLENGTH)
                    ++wordlen[nchar];
            }
            inspace = IN;
            nchar = 0;
        }
        else
        {
            ++nchar;
            if (c == '"' || c == '\'')
                --nchar;
            inspace = OUT;
        }
    }
    vhistogram(wordlen, MAXLENGTH);
    return 0;
}
int vhistogram(int wordlen[], int maxlength)
{
    int longest, most, i;
    longest = most = 0;
    for (i = 1; i < maxlength; ++i)
    {
        if (wordlen[i] && i > longest)
            longest = i;
        if (wordlen[i] > most)
            most = wordlen[i];
        if (wordlen[i])
            printf("%2d words of length %d\n", wordlen[i], i);
    }
    printf("greatest word length: %d\n", longest);
    printf("most words of a given length: %d\n", most);
    int j, k; /* index to rows and columns in vertical histogram */
    for (j = most; j > 0; j--)
    {
        printf("%5d:   ", j);
        for (k = 1; k < maxlength; k++)
        {
            if (wordlen[k] < j)
                printf("    ");
            else
                printf("*   ");
        }
        putchar('\n');
    }
    printf("      ");
    for (i = 1; i < maxlength; i++)
        printf("====");
    printf("\nWd ln:");
    for (i = 1; i < maxlength; i++)
        printf("%4d", i);
    putchar('\n');
    return 0;
}
