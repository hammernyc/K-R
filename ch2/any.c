/**
 * exercise 2-5
*/
#include <stdio.h>
int any(char str1[], char str2[]);

int main(int argc, char *argv[])
{
    printf("%d\n", any("hi", "there"));
    printf("%d\n", any("hi", "tere"));
    return 0;
}

int any(char str1[], char str2[])
{
  int i, j;

  for (i = 0; str1[i] != '\0'; i++) {
     for (j = 0; str2[j] != '\0'; j++) {
        if (str1[i] == str2[j]) {
            return i;
        }
    } 

  }
 
  return -1;
}
