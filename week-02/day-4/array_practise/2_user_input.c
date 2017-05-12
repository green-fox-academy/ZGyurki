#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets

    puts("Whats your name? ");
    gets(buffer);

    //TODO:
    // Print it out with puts

    puts(buffer);

    //TODO:
    // Get the user's pet name with getch

    puts("Whats your pet name? ");
    buffer = getchar();

    //TODO:
    // Print it out

    printf("%s", buffer);

    return 0;
}
