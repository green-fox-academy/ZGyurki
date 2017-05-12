#include <stdio.h>

int main() {
    int numbers[] = {5, 6, 17, 8, 9}; //átírtam 17-re a 3. elemet, hogy láthatóvá váljon, hogy nem az értékhez, hanem a memória címhez adok hozzá 2-õt
    int* number_pointer = &numbers[0];
    //TODO:
    // The "number_pointer" should point to the third element of the array called "numbers",
    // than please print its value with it. Solve the problem without reusiong the "&" operator
    // for geting the address of the third element.

    printf("%d\n", *number_pointer); //itt kezdõdik a bizonyítás - kiiratom number_pointer értékét (ami numbers 0. eleme)
    printf("%d\n", number_pointer); //a number_pointerben tárolt memória cím
    number_pointer += 2;
    printf("%d\n", number_pointer); //az új memória cím
    printf("%d", *number_pointer); // az új érték amire így a pointer mutat & nélkül

    return 0;
}
