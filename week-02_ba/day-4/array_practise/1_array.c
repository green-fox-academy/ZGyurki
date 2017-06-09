#include <stdio.h>

int main() {
    char my_name_array[] = "My Name";

	//TODO:
    // Print out the array character-by-character

    for( int n = 0; n < sizeof(my_name_array); n += 1 )
    {
      printf("%c\n", my_name_array[n]);
    }

    return 0;
}
