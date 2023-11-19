#include <stdio.h>
/* important understanding of it*/
typedef union
{
    float f;
    unsigned u;
} bit_float_t;

float bit2float(unsigned u)
{
    bit_float_t arg;
    arg.u = u;
    return arg.f;
}

unsigned float2bit(float f)
{
    bit_float_t arg;
    arg.f = f;
    return arg.u;
}

int main()
{
    unsigned a = 1066192077;
    float b = bit2float(a);
    printf("%f\n", b);

    float c = 1.1;
    unsigned d = float2bit(c);
    printf("%u\n", d);
    return 0;
}