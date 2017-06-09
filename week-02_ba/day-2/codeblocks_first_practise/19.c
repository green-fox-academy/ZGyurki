#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;
	if (b % a == 3)
    {
       printf("the reminder of b devided by a is 3");
    }
    else
    {
        printf("the reminder is not 3, but divided by 3 ;)");
    }
	// Tell if the reminder of b devided by a is 3

	return 0;
}
