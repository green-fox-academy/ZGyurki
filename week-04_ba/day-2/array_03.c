#include <stdio.h>

int main()
{
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

    //TODO:
    // Print out the content of the arrays

    int len;
    len = sizeof(float_array) / sizeof(float_array[0]);
    for (int i = 0; i < 5; i++){
        printf("%d\t", int_array[i]);
    }
    printf("\n");
    for (int j = 0; j < len; j++){
        printf("%.2f\t", float_array[j]);
    }
    return 0;
}
