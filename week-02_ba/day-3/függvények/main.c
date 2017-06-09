#include <stdio.h>

/* Write a non void function which has a paramters (let's say for example x).
The funtion than returns the "xth" fibonaci number.
What the hack is a fibonacci number? Search it on wikipedia!
*/

int fib(n)
{
    if (n < 2)
    {
        return n;
    }
    return (fib(n-2) + fib(n-1));
}

int main ()
{
    int result;
    result = fib(40);
    printf("%d\n", result);

    return 0;
}
