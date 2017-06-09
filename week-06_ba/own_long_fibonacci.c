#include <stdio.h>

unsigned long long get_fib(int pos)
{
    unsigned long long first = 0;
    unsigned long long second = 1;
    unsigned long long actual;

    if (pos <= 0) {
        return -1;
    } else if (pos == 1) {
        actual = first;
    } else if (pos == 2) {
        actual = second;
    } else {
        for (int i = 2; i < pos; i++) {
            actual = first + second;
            first = second;
            second = actual;
        }
    }
    return actual;
}

int main()
{
    //int pos;
    //printf("Give me a number: ");
    //scanf("%d", &pos);
    printf("The item is: %llu", get_fib(50000001));
    return 0;
}
