#include <stdio.h>
#include <stdint.h>

struct bitfield {
    uint8_t boolean_value_1:1;
    uint8_t boolean_value_2:1;
    uint8_t boolean_value_3:1;
    uint8_t boolean_value_4:1;
    uint8_t boolean_value_5:1;
    uint8_t boolean_value_6:1;
    uint8_t boolean_value_7:1;
    uint8_t boolean_value_8:1;
}bit_f;

struct not_bitfield {
    uint8_t boolean_value_1;
    uint8_t boolean_value_2;
    uint8_t boolean_value_3;
    uint8_t boolean_value_4;
    uint8_t boolean_value_5;
    uint8_t boolean_value_6;
    uint8_t boolean_value_7;
    uint8_t boolean_value_8;
}bit_f_n;

int main()
{
    // TODO:
    // Print out the size of both structs (use sizeof() function)

    printf( "Memory size occupied by bitfield : %d\n", sizeof(bit_f));
    printf( "Memory size occupied by not bitfield : %d\n", sizeof(bit_f_n));

    return 0;
}
