#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m,
                                                int n)
{
    assert(document);
    assert(n <= 5);
    return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m)
{
    assert(document);
    assert(m <= 5);
    char **kthSentence = document[m - 1][k - 1];
    return kthSentence;
}

char ***kth_paragraph(char ****document, int k)
{
    assert(document);
    assert(k <= MAX_PARAGRAPHS);
    return document[k - 1];
}

char ****get_document(char *text)
{
    char ****doc = NULL;
    int paragraphPtr = 0;
    int sentencePtr = 0;
    int wordPtr = 0;
    doc = malloc(sizeof(char ***));
    doc[0] = malloc(sizeof(char **));
    doc[0][0] = malloc(sizeof(char *));
    char *word = NULL;

    for (char *s = text; *s; ++s)
    {
        if (*s == ' ' || *s == '.')
        {
            doc[paragraphPtr][sentencePtr][wordPtr] = word;
            wordPtr++;
            doc[paragraphPtr][sentencePtr] = realloc(
                doc[paragraphPtr][sentencePtr], sizeof(char *) * (wordPtr + 1));
            if (*s == '.' && s[1] != '\n')
            {
                wordPtr = 0;
                sentencePtr++;
                doc[paragraphPtr] = realloc(
                    doc[paragraphPtr], sizeof(char **) * (sentencePtr + 1));
                doc[paragraphPtr][sentencePtr] = malloc(sizeof(char *));
            }
            *s = 0; /* Cut end the string */
            word = NULL;
        }
        else if (*s == '\n')
        {
            *s = 0;
            word = NULL;
            wordPtr = 0;
            sentencePtr = 0;
            paragraphPtr++;
            doc = realloc(doc, sizeof(char ***) * (paragraphPtr + 1));
            doc[paragraphPtr] = malloc(sizeof(char **));
            doc[paragraphPtr][sentencePtr] = malloc(sizeof(char *));
        }
        else
        {
            if (!word)
            {
                word = s;
            }
        }
    }
    return doc;
}
