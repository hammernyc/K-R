#include <stdio.h>
#include <limits.h>
#define US_BIT_WIDTH (sizeof (unsigned) * CHAR_BIT)

unsigned rightrot(int x, int n);

int main(int argc, char *argv[])
{
    printf("rightrot(%u, %d) = %x\n", 15, 2, rightrot(15, 2));
}

unsigned rightrot(int x, int n)
{
    unsigned ux = x;
    unsigned un = n;

    int n1s = ~(~0 << un);
    int rightbits = ux & n1s;
    int leftbits = rightbits << (US_BIT_WIDTH - n);
    return (ux >> un) | leftbits;
}