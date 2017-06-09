#include <stdio.h>
#include <stdlib.h>

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */

 int get_fibonacci_number(N)
 {
     int bef_prev = 0;
     int prev = 1;
     int creation;

     if (N < 1)
     {
         printf("\nThis is an invalid number ;)");
         return -1;
     }
     else if (N == 1)
     {
         return bef_prev;
     }
     else if (N == 2)
     {
         return prev;
     }
     else
     {
         for (int i = 2; i < N; i++)
         {
             creation = bef_prev + prev;
             bef_prev = prev;
             prev = creation;
         }
     }
     return creation;
 }

int main()
{
    int N;
    int N_num;
    printf("Hello!\n\nGive me a number (X),\nand I'll give you back a fibonacci number in that position: ");
    scanf("%d", &N);
    N_num = get_fibonacci_number(N);
    printf("\nAnd..the %d. fibonacci number is: %d\n", N, N_num);

    return 0;
}
