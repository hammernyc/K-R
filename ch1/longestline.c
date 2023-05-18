#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE]; /* current input line*/

int grabline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char str[]);

/* prints longest input line */
int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char longest[MAXLINE]; /* longest line saved so far */
    extern char line[MAXLINE];    

    while((len = grabline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        reverse(longest);
        printf("reversed (len %d): %s", max, longest);
    return 0;
}

/* grabline: read a line into buf (up to length lim), return length */
int grabline(char buf[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        buf[i] = c;
    if (c == '\n') {
        buf[i] = c;
        ++i;
    }
    buf[i] = '\0';
    return i;
}

/* copy: copy `from  into  `to`; assume `to` is big enough. */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

/* reverse: reverse string str in-place */
void reverse(char str[]) {
    int c, start, end;
    c = start = end = 0;
    while (str[end + 1] != '\0')
        end++;
    
    while (start < end) {
        c = str[start];
        str[start] = str[end];
        str[end] = c;
        ++start;
        --end;
    } 
}
