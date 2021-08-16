#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
int main(void) {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state ==
             OUT) { /* This means if c is not blank, newline or tab, and the
                       previous state is OUT, now c comes to a word */
      state = IN;
      ++nw;
    }
  }
  printf("%d lines, %d words, %d characters", nl, nw, nc);
  return 0;
}
