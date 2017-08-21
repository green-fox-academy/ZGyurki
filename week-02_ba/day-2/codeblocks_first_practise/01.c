#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "This a sample string1.This a sample string2.This a sample string3.\n";
    char buff[3][50];
    char * pch;

    pch = strtok(str, ".");

    int i = 0;
    while (pch != NULL) {
        strcpy(buff[i], pch);
        pch = strtok(NULL, ".");
        i++;
    }
    for (i = 0; i < 3; i++){
        printf ("%s\n", buff[i]);
        pch = strtok(buff[i], " ");
        while (pch != NULL) {
            printf("%s\n", pch);
            pch = strtok(NULL, " ");
        }
    }

    printf("\nFinally done AND cool!\n");
    printf("%d", sizeof(buff) / sizeof(buff[0]));
    return 0;
}
