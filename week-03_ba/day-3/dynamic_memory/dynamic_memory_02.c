#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it should print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {

    int count, i, j;
    int sum = 0;
    printf("Give me a 'count': ");
    scanf("%d", &count);
    int* array = (int*) calloc(count, sizeof(int));

    for(i = 0; i < count; ++i){
        printf("Write a number to me: ");
        scanf("%d", &array[i]);
        sum += array[i];
    }

    printf("\n%d\n", (sum / count));

    free(array);

  return 0;
}
