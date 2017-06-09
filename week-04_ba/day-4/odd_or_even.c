#include <stdio.h>
#include <stdlib.h>

/*
Write a program that reads a number form the standard input,
than prints "Odd" if the number is odd, or "Even" it it is even.
*/

int main()
{
    int number;
    printf("Give me a number, then I'll say is it odd or even: \n");
    scanf("%d", &number); //& jel fontos, hogy számot eltároljon a változóban
    if (number % 2 == 0)
    {
        printf("It is EVEN!\n");
    }
    else
    {
        printf("It is ODD!\n");
    }
    return 0;
}
