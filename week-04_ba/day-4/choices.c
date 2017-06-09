#include <stdio.h>
#include <stdlib.h>

//make it work

int main()
{
    int number = 100;
    int *number_ptr = &number;
    int decision;

    printf("\t**********\n\tHello User\n\t**********\n\nYou have an integer named 'number'..\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n\n");
    printf("What's your decision: ");
    scanf("%d", &decision);

    if (decision == 1)
    {
        printf("%d\n", number_ptr);
    }
    else if (decision == 2)
    {
        printf("%d\n", *number_ptr);
    }
    else if (decision == 3)
    {
        printf("%d\n", (*number_ptr * 2));
    }
    else
    {
        printf("It is an invalid number, ahh..\n");
    }
    return 0;
}
