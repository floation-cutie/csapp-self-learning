#include <stdio.h>
#include <stdlib.h>
/* 局部变量中数组是如何被存储的*/
int recurse(int x)
{
    int a[2 << 15];
    /* 2~17 =  128 KiB */
    printf("x = %d. a at %p\n", x, a);
    a[0] = (2 << 13) - 1;
    a[a[0]] = x - 1;
    if (a[a[0]] == 0)
        return -1;
    return recurse(a[a[0]]) - 1;
}

int main()
{
    recurse(46);
    system("pause");
    return 0;
}