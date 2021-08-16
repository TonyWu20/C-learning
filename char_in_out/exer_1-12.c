#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
int main(void) {
  int c, state;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t') {
      state = IN;
      putchar(c);
    } else {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      } /* Skip when state == OUT and c is any of ' ', '\n', '\t' */
    }
  }
  return 0;
}
int wrong(void) { /* This is wrong solution, since it can't suppress
                     blanks/tabs/newlines */
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t')
      putchar('\n');
    else
      putchar(c);
  }
  return 0;
}
