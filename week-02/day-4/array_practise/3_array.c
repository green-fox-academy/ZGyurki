#include <stdio.h>

int main() {
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

	//TODO:
    // Print out the content of the arrays

    for( int n = 0; n < sizeof(int_array); n += 1 )
    {
      printf("%d\t", int_array[n]);
    }
    printf("\n");
    for( int n = 0; n < sizeof(float_array); n += 1 )
    {
      printf("%f\t", float_array[n]);
    }

    return 0;
}
