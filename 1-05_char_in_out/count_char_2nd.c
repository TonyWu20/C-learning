#include <stdio.h>

int main(void) {
  double nc;
  for (nc = 0; getchar() != EOF; ++nc)
    ; /* empty body for the loop: null statement */
  printf("%.0f \n", nc);
  return 0;
}