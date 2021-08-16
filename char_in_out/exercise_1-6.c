#include <stdio.h>
/* Verify that the expression getchar() != EOF is 0 or 1. */

int main(void) {
  int c;
  while ((c = getchar()) != EOF)
    putchar(c);
  return 0;
}
