#include <stdio.h>
#include <stdint.h>

void printf_numbers(unsigned long from, unsigned long to)
{
	for (unsigned long i = from; i < to; i++){
        printf("%lu,", i);
	}
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
