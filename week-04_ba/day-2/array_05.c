#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.
double calc_avg(double *array, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += array[i];
    }
    return (float)sum / len;
}

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.
double under_avg(double *array, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++){
        if (array[i] < calc_avg(array, len)){
            count += 1;
        }
    }
    return count;
}

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.
double *allocate(double *array, int len)
{
    int count = 0;
    double *new_array = (double*) calloc(under_avg(array, len), sizeof(double));
    for (int i = 0; i < len; i++){
        if (array[i] < calc_avg(array, len)){
            new_array[count] = array[i];
            //printf("%.f\n", new_array[count]);
            count += 1;
        }
    }
    return new_array;
}


int main()
{
    int len;
    double *catcher;
    double array[] = {1, 2, 5, 10, 33, 107, 444};
    len = sizeof(array) / sizeof(array[0]);
    printf("%.2f\n", calc_avg(array, len));
    printf("%.f\n", under_avg(array, len));
    catcher = allocate(array, len);
    for (int i = 0; i < under_avg(array, len); i++){
            printf("%.f\t", catcher[i]);
    }
    return 0;
}
