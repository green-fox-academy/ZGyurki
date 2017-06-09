#include <stdio.h>

//TODO:
// Print out the two arrays character-by-character

//TODO:
// What is the difference between the arrays?

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'}; //itt van egy lezáró karakter a végén
    char char_array_the_same[] = "abcd";

    int length_a = strlen(char_array);
    int length_b = strlen(char_array_the_same);

    for (int i = 0; i < length_a; i++){
        printf("%c\t", char_array[i]);
    }
    printf("\n");
    for (int j = 0; j < length_b; j++){
        printf("%c\t", char_array_the_same[j]);
    }
    return 0;
}
