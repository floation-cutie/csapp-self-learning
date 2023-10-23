#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int Mydiv(int a, int b)
{
    // 实现a/b的向0舍入,规定b为正数,2的幂
    int isNeg = a & INT32_MIN;
    (isNeg && (a = a + (1 << b) - 1));
    return a >> b;
}
int mul3div4(int x)
{
    // 考虑取整问题
    int mul = (x << 1) + x;
    return Mydiv(mul, 2);
}
int main()
{
    printf("%d\n", mul3div4(20));
    system("pause");
    return 0;
}