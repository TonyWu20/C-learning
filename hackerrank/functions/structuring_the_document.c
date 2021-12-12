#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word
{
    char *data;
};

struct sentence
{
    struct word *data;
    int word_count;
};

struct paragraph
{
    struct sentence *data;
    int sentence_count;
};

struct document
{
    struct paragraph *data;
    int paragraph_count;
};

typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;
typedef struct document document;

void add_char(word *wordPtr, char c)
{
    static int size;
    if (!wordPtr->data)
    {
        wordPtr->data = NULL;
        size = 2;
    }
    wordPtr->data = realloc(wordPtr->data, sizeof(char) * size);
    wordPtr->data[size - 1] = 0;
    wordPtr->data[size - 2] = c;
    size++;
}

void add_word(sentence *sentencePtr, word *wordPtr)
{
    if (!sentencePtr->data)
    {
        sentencePtr->data = NULL;
        sentencePtr->word_count = 0;
    }
    sentencePtr->word_count++;
    sentencePtr->data =
        realloc(sentencePtr->data, sizeof(word *) * sentencePtr->word_count);
    sentencePtr->data[sentencePtr->word_count - 1] = *wordPtr;
    wordPtr->data = NULL;
}

void add_sentence(paragraph *paraPtr, sentence *sentencePtr)
{
    if (!paraPtr->data)
    {
        paraPtr->data = NULL;
        paraPtr->sentence_count = 0;
    }
    paraPtr->sentence_count++;
    paraPtr->data =
        realloc(paraPtr->data, sizeof(sentence) * paraPtr->sentence_count);
    paraPtr->data[paraPtr->sentence_count - 1] = *sentencePtr;
    sentencePtr->data = NULL;
}

void add_paragraph(document *doc, paragraph *paraPtr)
{
    if (!doc->data)
    {
        doc->data = NULL;
        doc->paragraph_count = 0;
    }
    doc->paragraph_count++;
    doc->data = realloc(doc->data, sizeof(paragraph) * doc->paragraph_count);
    doc->data[doc->paragraph_count - 1] = *paraPtr;
    paraPtr->data = NULL;
}

document get_document(char *text)
{
    document doc;
    paragraph paraPtr;
    sentence sentencePtr;
    word wordPtr;
    doc.data = NULL;
    paraPtr.data = NULL;
    sentencePtr.data = NULL;
    wordPtr.data = NULL;
    int textLen = strlen(text);
    for (int i = 0; i <= textLen; ++i)
    {
        switch (text[i])
        {
        case ' ':
            add_word(&sentencePtr, &wordPtr);
            break;
        case '.':
            add_sentence(&paraPtr, &sentencePtr);
            break;
        case '\n':
        case '\0':
            add_paragraph(&doc, &paraPtr);
            break;
        default:
            add_char(&wordPtr, text[i]);
            break;
        }
    }
    return doc;
}
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc,
                                                      int k, int m, int n)
{
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    return Doc.data[k - 1];
}
void print_word(struct word w)
{
    printf("%s", w.data);
}

void print_sentence(struct sentence sen)
{
    for (int i = 0; i < sen.word_count; i++)
    {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1)
        {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para)
{
    for (int i = 0; i < para.sentence_count; i++)
    {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc)
{
    for (int i = 0; i < doc.paragraph_count; i++)
    {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char *get_input_text()
{
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main()
{
    char *text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w =
                kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else
        {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}
