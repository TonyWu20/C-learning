#include <ctype.h>
#include <math.h> /* for fmod() */
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */

int getop(char[]);
void push(double);
double pop(void);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
/* getch and ungetch shares a buffer and the index. The buffer and index must be
 * external to both routines*/
int getch(void);
void ungetch(int);
/* getch and ungetch */
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* new command section */
void showTop(void);
void duplicate(void);
void swapItems(void);
/* end of new command declaration */
void showTop(void)
{
    if (sp > 0)
        printf("Top of stack contains: %8g\n", val[sp - 1]);
    else
        printf("Stack is empty!\n");
}

void duplicate(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

void swapItems(void)
{
    double item1 = pop();
    double item2 = pop();
    push(item1);
    push(item2);
}

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
                printf("error: zero divisor\n");
        case '#':
            duplicate();
            break;
        case '~':
            swapItems();
            break;
        case '?':
            showTop();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-')
    {
        s[i] = c;
        if (!isdigit(c = getch()))
        {
            return '-';
        }
        else
            s[++i] = c;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
