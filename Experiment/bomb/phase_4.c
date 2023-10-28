#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int edi; // 第一个参数
int edx = 14;
int eax = 2;
int esi = 0;
int ebx = 1000;
int tmp;
void func()
{
    tmp = ebx;
    eax = edx;
    eax -= esi;
    ebx = eax;
    ebx >>= 31;
    eax += ebx;
    eax >>= 1;
    ebx = eax + esi;
    if (ebx - edi <= 0)
    {
        goto s;
    }
    else
    {
        edx = ebx - 1;
        func();
    }

    eax += ebx;
    goto t;
s:
    eax = ebx;
    if (ebx - edi >= 0)
    {
        goto t;
    }

    esi = ebx + 1;
    func();
    eax += ebx;

t:
    ebx = tmp;
    return;
}
int main()
{

    edi = 15;
    func();
    printf("%d\n", eax);
    // esi = 8 eax6 ebx3 ebx11 eax11 esi4 eax14 10 5 ebx 9 esi10 eax4 2 esi13 eax13 esi14

    return 0;
}