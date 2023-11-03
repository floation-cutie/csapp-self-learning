#include <stdlib.h>
#include <stdio.h>
long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    // do nothing
    case 62:
        result *= 8;
        break;
    case 63:
        result >>= 3;
        break;
    case 64:
        result <<= 4;
        result -= x;
        x = result;
    case 65:
        x *= x;
    default:
        result = x + 0x4b;
        break;
    }
    return result;
}

int main()
{
    printf("%ld\n", switch_prob(23, 60));
    system("pause");
    return 0;
}