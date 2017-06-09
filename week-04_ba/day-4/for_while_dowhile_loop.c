#include <stdio.h>
#include <stdlib.h>

/*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"
Do it with:
    - for loop
    - while loop
    - do while loop
Also create a function which does the same.
*/

void do_it_with_for()
{
    for (int i = 1; i < 101; i++)
    {
        printf("%d) I won't cheat on the test!\n", i);
    }
}

void do_it_with_while()
{
    int i = 1;
    while (i < 101)
    {
        printf("%d) I won't cheat on the test!\n", i);
        i ++;
    }
}

void do_it_with_dowhile()
{
    int i = 1;
    do
    {
        printf("%d) I won't cheat on the test!\n", i);
        i ++;
    }while (i < 101);
}

int main()
{
    do_it_with_dowhile();

    return 0;
}
