#include <stdio.h>
/* Count blanks, tabs, and newlines */

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\\') {
      putchar('\\');
      putchar('\\');
    }

    if (c == '\t') {
      putchar('\\');
      putchar('t');
    }
    if (c == '\b') {
      putchar('\\');
      putchar('b');
    }
    if (c != '\t' || c != '\b' || c != '\\')
      putchar(c);
  }
  return 0;
}
