#include <stdio.h>
/* Print Celsius-Fahrenheit table
 * for fahr = 0, 10, ..., 100; floating-point version */
#define LOWER 0
#define UPPER 100
#define STEP 10
float celsius(int m);
int main(void)
{
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f\n", fahr, celsius(fahr));
    return 0;
}
float celsius(int fahr)
{
    float celsius;
    celsius = (fahr - 32) * (5.0 / 9.0);
    return celsius;
}
