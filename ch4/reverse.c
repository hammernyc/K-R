#include <stdio.h>
#include <string.h>

void reverse(char str[], int first, int last);

int main(int argc, char *argv[])
{
    char str[] = "hello world!";
    reverse(str, 0, strlen(str) - 1);
    printf("%s\n", str);
    return 0;
}

void reverse(char str[], int first, int last){
    char temp;
    if (last <= first)
        return;

    temp = str[first];
    str[first] = str[last];
    str[last] = temp;
    reverse(str, ++first, --last);
}
