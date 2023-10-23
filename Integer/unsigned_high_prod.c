#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> sizeof(int) * 8;
}

unsigned test(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> sizeof(unsigned) * 8;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int msbX = (x >> (sizeof(unsigned) * 8 - 1)) & 1;
    int msbY = (y >> (sizeof(unsigned) * 8 - 1)) & 1;
    unsigned t = (msbX * msbY) << 31;
    unsigned ret = msbX * y +
                   msbY * x +
                   //(t << 1)
                   +signed_high_prod(x, y);
    return ret;
}
int main()
{
    unsigned x, y;
    scanf("%u%u", &x, &y);
    if (test(x, y) == unsigned_high_prod(x, y))
        printf("Match\n");
    else
        printf("Fail\n");
    system("pause");
    return 0;
}