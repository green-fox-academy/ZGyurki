#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double GetSurface(struct rectangular_cuboid x)
{
    return 2*(x.a*x.b+x.a*x.c+x.b*x.c);
}

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
double GetVolume(struct rectangular_cuboid x)
{
    return (x.a*x.b*x.c);
}

int main()
{
    struct rectangular_cuboid test = {5, 6, 7};
    printf("%.1f\n", GetSurface(test));
    printf("%.1f\n", GetVolume(test));

    return 0;
}
