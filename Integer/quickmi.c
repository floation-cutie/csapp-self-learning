#include <stdio.h>
#include <stdlib.h>
int mul17(int x)
{
    return (x << 4) + x;
}
int mulm7(int x)
{
    return x - (x << 3);
}
int mul60(int x)
{
    return (x << 6) - (x << 2);
}
int mulm112(int x)
{
    return (x << 4) - (x << 7);
}
int main()
{
    printf("17 * 123 = %d\n", mul17(123));
    printf("(-7) * 123 = %d\n", mulm7(123));
    printf("60 * 123 = %d\n", mul60(123));
    printf(" (-112) * 123 = %d\n", mulm112(123));
    system("pause");
}
