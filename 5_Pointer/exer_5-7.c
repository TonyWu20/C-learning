#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
char *lineptr[MAXLINE]; /* pointers to text lines */

int readlines(char *lineptr[], char *temp, int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(char *lineptr[], int left, int right);
int nlines;

/* sort input lines */
int main(void)
{
    char lines[10000];
    extern int nlines;
    if ((nlines = readlines(lineptr, lines, MAXLINE)) >= 0)
    {
        my_qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int my_getline(char *, int);
char *alloc(int);
void afree(char *p);
int my_getline(char *s, int lim)
{
    int c;
    char *ps = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - ps;
}
/* readlines: read input of lines */
int readlines(char *lineptr[], char *temp, int maxlines)
{
    int len, nlines;
    char *p;
    char line[MAXLEN];
    nlines = 0;
    p = temp + strlen(temp);
    while ((len = my_getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (strlen(temp) + len) >= MAXLEN)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    p = 0;
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void my_qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    swap(v, left, last);
    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
