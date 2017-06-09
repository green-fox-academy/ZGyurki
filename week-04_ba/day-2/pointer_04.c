#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Add two numbers using pointers
*/


int main()
{

    int a  = 20;
    int b = 17;
    int *a_ptr = &a;
    int *b_ptr = &b;
    printf("%d", *a_ptr + *b_ptr);

    return 0;
}
