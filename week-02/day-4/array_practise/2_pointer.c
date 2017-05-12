#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;
    int* egy = &*number_pointer;
    int* ketto = &*egy;
    //TODO:
    // print the value of number using the "number_pointer"

    printf("%x\n", &number); //number memória címe
    printf("%x\n", number_pointer); //u.a. csak így a number_pointer tartalma felõl közelítve
    printf("%d\n", *number_pointer); //a number_pointeren keresztül a number tartalma
    printf("%d\n", *ketto); //az egy pointeren keresztül és a number_pointeren keresztül a number tartalma

    return 0;
}
