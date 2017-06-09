#include<stdio.h>

int main ()
{
  int times=5;
  int myArray[5];
  int n = 0;

   for( n = 1; n <= times; n = n + 1 )
   {
      myArray[n] = n;
      printf("%d\n", n);
   }
   int a = myArray[3];
   printf("%d", a);
   return 0;
}
