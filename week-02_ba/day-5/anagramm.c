#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    char myArray[255] = {"macika"};
    //printf("Please give me a word, and I change it to 'palindrome': ");
    //scanf("%s", myArray);
    printf("%d\n", strlen(myArray));
    printf("%c", myArray[0]);

    //scanf("%c", );
    printf("\n%s", myArray);
    char *one = &myArray[0];
    char *two = &myArray[1];
    printf("%c", *one);
    printf("%c", *two);


    return 0;
}
