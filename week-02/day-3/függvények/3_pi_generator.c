#include <stdio.h>

/* Write a non void function which returns the value of PI, so the following number:
3.14159
Try it out in the main function by printing out the result of the pi generator function!
*/

float pi_generator();

int main(){
    float pi;
    pi = pi_generator();
    printf("%f", pi);
    return 0;
}

float pi_generator() {

   return 3.14159;

}
