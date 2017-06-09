#include <stdio.h>
#include <stdlib.h>

//make it work

int main()
{
    int number = 100;
    int decision;

    printf("\t**********\n\tHello User\n\t**********\n\nYou have an integer named 'number'..\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n\n");
    printf("What's your decision: ");
    scanf("%d", &decision);

    switch(decision){
    case 1:
        printf("%d\n", &number);
        break;
    case 2:
        printf("%d\n", number);
        break;
    case 3:
        printf("%d\n", (number * 2));
        break;
    default:
        printf("It is an invalid number, ahh..\n");
        break;
    }
    return 0;
}
