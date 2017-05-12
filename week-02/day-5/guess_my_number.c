#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int container;
    int guess;
    int life = 5;
    int count = 0;
    printf("Hi! I wanna play a game! (LOL)\n\nTell me a number: ");
    scanf("%d", &container);
    int r = rand() % (container +1);
    printf("\nI also have a number for U, beetween 0 and %d.\n", container);

    while (count != 6)
    {
        if (life - count == 0)
        {
            printf("\nNO more life..\nTime to DIE!!!\n\n");
            printf("\n(The number actually was: %d)\n", r);
            break;
        }
        else
        {
            printf("\nU have %d life, guess: ", (life - count));
            scanf("%d", &guess);
            if (r > guess)
            {
                printf("Wrong, the number is bigger.\n");
            }
            else if (r < guess)
            {
                printf("Wrong, the number is smaller.\n");
            }
            else if (r == guess)
            {
                printf("Lucky..\n");
                break;
            }
        }
        count++;
    }
    return 0;
}
