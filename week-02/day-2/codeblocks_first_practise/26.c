#include <stdio.h>

int main() {
    int a = 1;
    while (a != 101)
    {
    if (a % 3 == 0)
    {
        if (a % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else
        {
            printf("Fizz\n");
        }
    }
    else if (a % 5 == 0)
    {
        if (a % 3 == 0)
        {
            printf("FizzBuzz\n");
        }
        else
        {
            printf("Buzz\n");
        }
    }
    else
    {
        printf("%d\n", a);
    }
    a++;
    }
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".
	return 0;
}
