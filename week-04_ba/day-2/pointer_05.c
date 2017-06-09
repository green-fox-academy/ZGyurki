#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */


int main()
{
    int number = 2017;
    int *number_ptr = &number;
    float Pi = 3.14;
    float *Pi_ptr = &Pi;
    char letter = 't';
    char *letter_ptr = &letter;

    printf("%p\n", number_ptr);
    printf("%p\n", &number);
    printf("%p\n", Pi_ptr);
    printf("%p\n", &Pi);
    printf("%p\n", letter_ptr);
    printf("%p\n", &letter);

    printf("%d\n", *number_ptr);
    printf("%d\n", number);
    printf("%.2f\n", *Pi_ptr);
    printf("%.2f\n", Pi);
    printf("%c\n", *letter_ptr);
    printf("%c\n", letter);

    return 0;
}
