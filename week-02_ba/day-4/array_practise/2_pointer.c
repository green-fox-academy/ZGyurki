#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;
    int* egy = &*number_pointer;
    int* ketto = &*egy;
    //TODO:
    // print the value of number using the "number_pointer"

    printf("%x\n", &number); //number mem�ria c�me
    printf("%x\n", number_pointer); //u.a. csak �gy a number_pointer tartalma fel�l k�zel�tve
    printf("%d\n", *number_pointer); //a number_pointeren kereszt�l a number tartalma
    printf("%d\n", *ketto); //az egy pointeren kereszt�l �s a number_pointeren kereszt�l a number tartalma

    return 0;
}
