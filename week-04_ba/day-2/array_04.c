#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/

char adding_str(char *str_1)
{
    char str_2[50];

    printf("I can 'concat' two words.\nGive me the first: ");
    scanf("%s", str_1); //függvénynél nem kell a & jel - segítség, ha varningnál type hibát ad
    printf("Now give me the socond one: ");
    scanf("%s", &str_2);

    strcat (str_1, str_2);

    return str_1;
}

int main ()
{
  char str_1[50];
  int len;

  adding_str(str_1);
  len = strlen(str_1);

  for (int i = 0; i < len; i++)
    {
        printf("%c", str_1[i]);
    }
  printf("\n");

return 0;
}
