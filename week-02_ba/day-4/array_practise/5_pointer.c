#include <stdio.h>

int main() {
    int numbers[] = {5, 6, 17, 8, 9}; //�t�rtam 17-re a 3. elemet, hogy l�that�v� v�ljon, hogy nem az �rt�khez, hanem a mem�ria c�mhez adok hozz� 2-�t
    int* number_pointer = &numbers[0];
    //TODO:
    // The "number_pointer" should point to the third element of the array called "numbers",
    // than please print its value with it. Solve the problem without reusiong the "&" operator
    // for geting the address of the third element.

    printf("%d\n", *number_pointer); //itt kezd�dik a bizony�t�s - kiiratom number_pointer �rt�k�t (ami numbers 0. eleme)
    printf("%d\n", number_pointer); //a number_pointerben t�rolt mem�ria c�m
    number_pointer += 2;
    printf("%d\n", number_pointer); //az �j mem�ria c�m
    printf("%d", *number_pointer); // az �j �rt�k amire �gy a pointer mutat & n�lk�l

    return 0;
}
