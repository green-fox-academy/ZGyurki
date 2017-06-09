#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function which receives a string as parameter, and returns
// the numbers of characters in the string.
// Don't use the strlen() function!
int count_str(char *sw)
{
    int letter = 0;
    while (sw[letter] != '\0'){
        letter += 1;
    }
    return letter;
}

int main()
{
    char some_word[100];
    printf("Give me a word, then I'll say how many letters you can find in it: ");
    scanf("%s", &some_word);
    printf("%d", count_str(some_word));

    return 0;
}
