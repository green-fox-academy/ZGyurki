#include <stdio.h>

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the digivolution level of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

enum digi_lev {
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
};

struct digimons {
    char name[127];
    int age;
    int health;
    char tamer_name[255];
    enum digi_lev level;
};

int get_minimum_health_index(struct digimons *smp, int len)
{
    int border_num = 1000;
    int index;
    for (int i = 0; i < len; i++) {
        if (smp[i].health < border_num) {
            border_num = smp[i].health;
            index = i;
        }
    }
    return index;
}

int get_same_digivolution_level_count(struct digimons *smp, int len, enum digi_lev lvl)
{
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (smp[i].level == lvl) {
            counter++;
        }
    }
    return counter;
}

int get_same_tamer_count(struct digimons *smp, int len, char *tamer)
{
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (!strcmp(smp[i].tamer_name, tamer)) {
            counter++;
        }
    }
    return counter;
}

float get_average_health_of_the_same_tamer(struct digimons *smp, int len, char *tamer)
{
    float health = 0;
    float counter = 0;
    for (int i = 0; i < len; i++) {
        if (!strcmp(smp[i].tamer_name, tamer)) {
            health += smp[i].health;
            counter++;
        }
    }
    return health / counter;
}

int main()
{
    struct digimons samples[] = {
        {"Bear", 1, 100, "Orson", BABY},
        {"Bunny", 2, 80, "Orson", IN_TRAINING},
        {"Cat", 3, 60, "Dave", ROOKIE},
        {"Dog", 4, 40, "George", ROOKIE},
        {"Pig", 5, 20, "Brenda", CHAMPION},
        {"Duck", 6, 10, "Orson", ULTIMATE},
    };

    int len = sizeof(samples) / sizeof(samples[0]);
    printf("%d\n", get_minimum_health_index(samples, len));
    printf("%d\n", get_same_digivolution_level_count(samples, len, ROOKIE));
    printf("%d\n", get_same_tamer_count(samples, len, "Dave"));
    printf("%.2f\n", get_average_health_of_the_same_tamer(samples, len, "Orson"));

    return 0;
}
