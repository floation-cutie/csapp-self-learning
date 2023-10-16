#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned high = x & (~0 << ((i + 1) << 3));
    unsigned low = x & ((1 << (i << 3)) - 1);
    unsigned ans = high + (b << (i << 3)) + low;
    return ans;
}
int main()
{
    int ans = replace_byte(0x12345678, 2, 0xAB);
    printf("%X\n", ans);
    ans = replace_byte(0x12345678, 0, 0xAB);
    printf("%X\n", ans);
    system("pause");
    return 0;
}

int lower_one_mask(int n)
{
    return (int)((uint64_t)1 << n) - 1;
}

int odd_ones(unsigned x)
{
    // 仅有后半段的比较有效
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    return (x & 1) ^ (x >> 1 & 1);
}
int good_int_size_is_32()
{
    int set_msb = (int)((uint64_t)1 << 31);
    int beyond_msb = (int)((uint64_t)1 << 32);
    return set_msb && !beyond_msb;
}