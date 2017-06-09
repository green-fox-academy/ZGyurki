#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum transmission {MANUAL,
                   AUTOMATIC,
                   CVT,
                   SEMI_AUTOMATIC,
                   DUAL_CLUTCH
};

struct car {
    char manufacturer_name [255];
    float car_price_eur;
    int year;
    enum transmission typo;
};

int get_older_cars_than(struct car *a, int age, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++){
        if (a[i].year > age){
            count ++;
        }
    }
    return count;
}

int get_transmission_count(struct car *a, int len, enum transmission t)
{
    int count = 0;
    for (int i = 0; i < len; i++){
        if (a[i].typo == t){
            count ++;
        }
    }
    return count;
}

int main() {

    struct car array[] = {
    {"Ford", 85000, 1, CVT},
    {"Opel", 50000, 2, MANUAL},
    {"Fiat", 63000, 3, SEMI_AUTOMATIC},
    {"Skoda", 20000, 5, CVT},
    {"Suzuki", 57000, 2, DUAL_CLUTCH},
    };

    int len = sizeof(array) / sizeof(array[0]);
    printf("%d\n", get_older_cars_than(array, 2, len));
    printf("%d", get_transmission_count(array, len, MANUAL));

    return 0;
}
