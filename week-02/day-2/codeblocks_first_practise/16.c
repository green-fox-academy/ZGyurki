#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t v = 426;
	if (v % 4 == 0)
    {
        printf("Yeah!\n");
    }
    printf("End of program");
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	return 0;
}
