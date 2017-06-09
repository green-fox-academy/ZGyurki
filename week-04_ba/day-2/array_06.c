#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters

struct house {
    char address[200];
    int price_eur;
    int num_room;
    int area_sqrm;
};

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
void worth(struct house *h)
{
    if ((h->price_eur / h->area_sqrm) < 400){
        printf("\nTotally worth it! ;)\n");
    }
    else{
        printf("\nIts 'higher than' or 'equal with' the market price..\n");
    }
}

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
void counts_house(struct house *h, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++){
        if ((h[i].price_eur / h[i].area_sqrm) < 400){
            count += 1;
        }
    }
    printf("Here you can see, how many houses are worth - based on its prices: %d\n", count);
}

int main()
{
    int num;
    int len;

    struct house villages[] = {
    {"1. street", 10000, 2, 50},
    {"2. street", 30000, 3, 80},
    {"3. street", 40000, 3, 100},
    {"4. street", 95000, 5, 200},
    {"5. street", 200000, 8, 330}
    };

    len = sizeof(villages) / sizeof(villages[0]);

    printf("Here is a house list. If you would like to know which one is worth its price\naccording to the market needs..");
    printf("\n\n1. street, 10000eur, 2r, 50nm\n2. street, 30000eur, 3r, 80nm\n3. street, 40000eur, 3r, 100nm\n4. street, 95000eur, 5r, 200nm\n5. street, 200000eur, 8r, 330nm");
    printf("\n\n..please pick a number beetween 1-5: ");
    scanf("%d", &num);
    worth(&villages[num - 1]);
    counts_house(villages, len);

    return 0;
}
