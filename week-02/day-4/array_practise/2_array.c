#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character

    for (int n = 0; n < sizeof(char_array); n += 1)
    {
        printf("%c\t", char_array[n]);
    }
    printf("\n");
    for (int n = 0; n < sizeof(char_array_the_same); n += 1)
    {
        printf("%c\t", char_array_the_same[n]);
    }

	//TODO:
    // What is the difference between the arrays?

    printf("\n\n");
    for (int n = 0; n < sizeof(char_array); n += 1)
    {
        printf("%d\t", char_array[n]);
    }
    printf("\n");
    for (int n = 0; n < sizeof(char_array_the_same); n += 1)
    {
        printf("%d\t", char_array_the_same[n]);
    }
    printf("\nExactly that + 0 character :)\n");
    return 0;
}
