// TODO: Include needed header files
#include <stdio.h>
#include "game.h"


void StringManipulator(char* str){
    uint32_t str_len = strlen(str);

    for(uint32_t i = 0; i < str_len; i++) {
        str[i] -= 1;
    }
}

void IntegerManipulator(int* num){
    *num = num - an_example_number;
}
