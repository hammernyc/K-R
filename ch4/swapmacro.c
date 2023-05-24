#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main(int argc, char *argv[])
{
    int a = 3;
    int b = 5;
    swap(int, a, b);

    printf("%d %d\n", a, b);

    return 0;
}
