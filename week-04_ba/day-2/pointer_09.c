#include <stdio.h>

int main()
{
    int high_number = 6655;
    int low_number = 2;

    int* hight_number_pointer = &low_number;
    int* low_number_pointer = &high_number;
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.

    int support = hight_number_pointer;
    hight_number_pointer = low_number_pointer;
    low_number_pointer = support;

    printf("%p\n", low_number_pointer);
    printf("%p", hight_number_pointer);

    return 0;
}
