#include <stdio.h>
#include <stdlib.h>

/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/

int main()
{
    char name[50]; //'char' -ba, mérettel stringként tárolva & jellel
    int number;
    printf("Give me your name: ");
    scanf("%s", &name);
    printf("Give me your age and then I'll say, when will U 100 years old: ");
    scanf("%d", &number); //& jel fontos, hogy számot eltároljon a változóban

    int difference = 100 - number;
    int future = 2017 + difference;

    printf("\n%s, your centenary will be %d years later, in %d :)\n", name, difference, future);

    return 0;
}
