#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

//Create a client app that ping the google.com to get than latency, and print it out.

int main()
{
    int i;
    printf("Checking if processor is available...");
    if(system(NULL))
        puts("Ok");
    else
        exit(EXIT_FAILURE);
    printf("Executing command PING...\n");
    i=system("ping index.hu -w 2");
    printf("The value returned was: %d.\n", i);
    return 0;
}
