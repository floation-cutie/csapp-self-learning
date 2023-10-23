#include <stdio.h>
#include <stdlib.h>
/*to determine whether the first parameter is le the second*/
unsigned f2u(float x)
{
    return *(unsigned *)&x;
}
int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /*to get the sign bits*/
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /*to enumerate all*/
    /*Give an expression using only ux,uy,sx and sy */
    /*speical case should be considered in the priority position*/
    return (ux << 1 == 0 && uy << 1 == 0) ||
           (sx && !sy) ||
           (sx && sy && ux >= uy) ||
           (!sx && !sy && ux <= uy);
}

int main()
{
    printf("%d\n", float_le(-0, +0));
    printf("%d\n", float_le(+0, -0));
    system("pause");
    return 0;
}