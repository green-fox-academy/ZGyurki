#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it should print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {

    int count;
    int i;
    printf("Give me a 'count': ");
    scanf("%d", &count);
    int sum = 0;
    int num;

    for(i = 0; i < count; ++i){
        printf("Write a number to me: ");
        scanf("%d", &num);
        sum += num;
    }

    printf("\n%d\n", (sum / count));

  return 0;
}
