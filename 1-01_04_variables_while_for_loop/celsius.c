#include <stdio.h>
/* Print Celsius-Fahrenheit table
 * for celsius = 0, 10, ..., 100; floating-point version */
#define LOWER 0
#define UPPER 300
#define STEP 30
int main(void) {
  int celsius;

  for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP)
    printf("%3d %6.1f\n", celsius, (9.0 / 5.0) * celsius + 32);
  return 0;
}
