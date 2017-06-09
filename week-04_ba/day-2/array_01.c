#include <stdio.h>
#include <string.h>

//TODO:
// Print out the array character-by-character

int main()
{
    char my_name_array[] = "My Name";
    int length = strlen(my_name_array);

    for (int i = 0; i < length; i++){
        printf("%c\n", my_name_array[i]);
    }
    return 0;
}
