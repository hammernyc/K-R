/**
 * Our binary search makes two tests inside the loop, when ont would suffice 
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop. 
 **/

#include <stdio.h>

#define SIZE 10

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[]) 
{
    int v[] = { -50, -2, 0, 2, 4, 5, 8, 11, 15, 23 };

    printf("binsearch(3, v, SIZE) = %d\n", binsearch(3, v, SIZE));
    printf("binsearch(0, v, SIZE) = %d\n", binsearch(0, v, SIZE));
    
    printf("binsearch(-50, v, SIZE) = %d\n", binsearch(-50, v, SIZE));
    printf("binsearch(23, v, SIZE) = %d\n", binsearch(23, v, SIZE));

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
 {
    int lo, hi, mid;
    lo = 0, mid = 0, hi = n - 1;

    while (lo <= hi && v[mid] != x) {
        mid = (lo + hi) / 2;
        if (x < v[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return v[mid] == x ? mid : -1;
 }
