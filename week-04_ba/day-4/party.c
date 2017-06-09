#include <stdio.h>
#include <stdlib.h>

// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys.**

// It should print "The party is excellent!" if the the number of girls and
// boys are equal and there are more people coming than 20**

// It should print "Quite cool party!"
// if there are more than 20 people coming but the girl - boy ratio is not 1-1**

// It should print: "Average party..."
// if there are less people coming than 20

// It should print: "Sausage party"
// if no girls are coming, regardless the count of the people

int main()
{
    int N_girls;
    int N_boys;

    printf("Hello!\n\nI'll ask U to give me 2 numbers, one for the girls and another for the boys.\nThat represents the attendance of a party.\n\n");
    printf("Give me the number of the girls: ");
    scanf("%d", &N_girls);
    printf("Give me the number of the boys: ");
    scanf("%d", &N_boys);

    if ((N_girls == N_boys) & (N_girls + N_boys > 20))
    {
         printf("\nThe party is excellent!\n");
    }
    else if (N_girls == 0)
    {
         printf("\nSausage party\n");
    }
    else if ((N_girls != N_boys) & (N_girls + N_boys > 20))
    {
         printf("\nQuite cool party!\n");
    }
    else if (N_girls + N_boys < 20)
    {
         printf("\nAverage party...\n");
    }
    return 0;
}
