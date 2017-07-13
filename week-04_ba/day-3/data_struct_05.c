#include <stdio.h>

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

void print_all_data(struct car *arr, int len, enum car_type samp)
{
    for (int i = 0; i < len; i++) {
        if (arr[i].type == samp) {
            if (samp == TESLA)
                printf("%.1f\n", arr[i].km);
            else
                printf("%.1f\t %.1f\n", arr[i].km, arr[i].gas);
        }
    }
}

int main()
{
    struct car array[] = {
        {VOLVO, 350, 45},
        {TESLA, 75, 0},
        {LAND_ROVER, 210, 53},
        {TESLA, 115, 0},
        {VOLVO, 420, 50},
    };

    int len = sizeof(array) / sizeof(array[0]);
    print_all_data(array, len, VOLVO);

    return 0;
}
