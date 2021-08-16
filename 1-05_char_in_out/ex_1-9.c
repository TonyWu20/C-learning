#include <stdio.h>
/* count lines in input */
#define NONBLANK '-'
int main(void) {
  int c, lastc;
  lastc = NONBLANK;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (lastc != ' ') /* if last character is not a blank */
        putchar(c);     /* skip when last character is blank */
    } else
      putchar(c);
    lastc = c;
  }
}
