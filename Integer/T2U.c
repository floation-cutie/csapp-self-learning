#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
int random()
{
    srand(time(NULL));
    return rand();
}

int main()
{
    int x = random();
    int y = random();

    unsigned ux = (unsigned)x;
    unsigned uy = (unsigned)y;
    x = INT32_MIN;
    if ((x < y) == (-x > -y))
        printf("A is 1\n");

    x = random();
    y = random();
    if (((x + y) << 4) + y - x == 17 * y + 15 * x)
        printf("B is 1\n");

    if (~x + ~y + 1 == ~(x + y))
        printf("C is 1\n");
    /*
     * right
     *
     * (ux - uy) == -(unsigned) (y - x)
     *   =>
     * -(ux - uy) == (unsigned) (y - x)
     *   =>
     * (ux - uy) == (unsigned) (x - y)
     */
    if ((ux < uy) == -(unsigned)(y - x))
        printf("D is 1\n");

    if (((x >> 2) << 2) <= x)
        printf("E is 1\n");
    system("pause");
}