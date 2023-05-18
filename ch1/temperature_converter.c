#include <stdio.h>

#define LOWER   0.0 /* symbolic constant (not a variable) */
#define UPPER 300.0
#define STEP   20.0

float ftoc(float f);
float ctof(float c);

/* print Farenheit-Celsius table for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr;
    printf("  F.       C. \n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%.1f\t%6.1f\n", fahr, ftoc(fahr));

    /*
    float fahr, celsius;
    int lower, upper, step;

    lower = 0.0;
    upper = 300;
    step = 20.0;

    fahr = lower;
    printf("  F.       C. \n");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%.1f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }   
    */
}

float ftoc(float f)
{
    return 5.0 * (f - 32.0) / 9.0;
}

float ctof( float c)
{
    return 9.0 * c / 5.0 + 32.0;
}
