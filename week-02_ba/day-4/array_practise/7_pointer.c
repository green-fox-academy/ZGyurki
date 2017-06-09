#include <stdio.h>

int main() {
    int high_number = 6655;
    int low_number = 2;

    int* high_number_pointer = &low_number;
    int* low_number_pointer = &high_number;
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.

    printf("%x\n", high_number_pointer);
    printf("%x\n", low_number_pointer);

    int middle_step = high_number;
    *low_number_pointer = low_number;
    *high_number_pointer = middle_step;

    printf("%d\n", *high_number_pointer);
    printf("%d\n", *low_number_pointer);

    printf("%x\n", high_number_pointer);
    printf("%x\n", low_number_pointer);

    high_number_pointer = &high_number;
    low_number_pointer = &low_number;

    printf("%d\n", *high_number_pointer);
    printf("%d\n", *low_number_pointer);

    printf("%x\n", high_number_pointer);
    printf("%x\n", low_number_pointer);

    return 0;
}
