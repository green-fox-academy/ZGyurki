#include <stdio.h>

struct pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
int sum_gold(struct pirate *p, int len)
{
    int gold = 0;
    for (int i = 0; i < len; i++){
        gold += p[i].gold_count;
    }
    return gold;
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
float avg_gold(struct pirate *p, int len)
{
    int gold = sum_gold(p, len);
    return (float)gold / len;
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg
int richest_pirate(struct pirate *p, int len)
{
    int rich = 0;
    int pir_name;
    for (int i = 0; i < len; i++){
        if ((p[i].gold_count > rich) & p[i].has_wooden_leg){
            rich = p[i].gold_count;
            pir_name = p[i].name;
        }
    }
    return pir_name;
}

int main()

{
    int length;
    int first_task;
    struct pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    length = sizeof(pirates) / sizeof(pirates[0]);
    printf("%d\n", sum_gold(pirates, length));
    printf("%.2f\n", avg_gold(pirates, length));
    printf("%s\n", richest_pirate(pirates, length));

    return 0;
}
