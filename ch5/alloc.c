#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* next free position */

int main(int argc, char *argv[])
{
    return 0;
}

/* returns a pointer to the next n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; /* old pointer */
    } else /* not enough room */
        return 0;
}

/* free storage pointed to by p*/
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
