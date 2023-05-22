#include <ctype.h>
#include <stdio.h>
#include <string.h>

char myString[20];

void lower(char str[]);

int main() 
{
    strcpy(myString, "HeLlO wOrLD!");
    lower(myString);
    printf("%s\n",myString);
}

void lower (char str[])
{
    int i, c;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        c = str[i];
        str[i] = (islower(c) ? c : tolower(c));
    }
}