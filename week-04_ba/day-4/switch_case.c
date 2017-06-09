#include <stdio.h>
#include <stdlib.h>

/*
Write a program which receives a number between 0-10 from the user.
It prints out the english word for that number on the screen.
For example if the user enters 8, the program prints out "Eight".
Use switch-case in this task!
Handle the invalid user input!
*/

int main()
{
    int N;

    printf("Hello!\n\nWrite me down a number beetween 0-10,\nand I'll give you back it in english: ");
    scanf("%d", &N);

    if ((N < 0) | (N > 10))
     {
         printf("\nThis is an invalid number ;)\n");
     }

     switch(N)
     {
        case 0:
            printf("\nAnd..your number is: zero!\n");
            break;
        case 1:
            printf("\nAnd..your number is: one!\n");
            break;
        case 2:
            printf("\nAnd..your number is: two!\n");
            break;
        case 3:
            printf("\nAnd..your number is: three!\n");
            break;
        case 4:
            printf("\nAnd..your number is: four!\n");
            break;
        case 5:
            printf("\nAnd..your number is: five!\n");
            break;
        case 6:
            printf("\nAnd..your number is: six!\n");
            break;
        case 7:
            printf("\nAnd..your number is: seven!\n");
            break;
        case 8:
            printf("\nAnd..your number is: eight!\n");
            break;
        case 9:
            printf("\nAnd..your number is: nine!\n");
            break;
        case 10:
            printf("\nAnd..your number is: ten!\n");
            break;
     }
    return 0;
}
