#include <stdio.h>

int power(int m, int n);

/* test power function */
int main()
{
    int i;
    for (i = 0; i < 10; i++)
        printf("power(2, %d) = %d; power(-3, %d) = %d\n",
            i, power(2, i), i, power(-3, i));
    return 0;
}

int power(int base, int exp)
{
    int i, p;
    p = 1;
    for (i = 1; i <= exp; i++)
        p *= base;
    return p;
}