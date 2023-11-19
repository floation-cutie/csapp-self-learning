#include <stdio.h>
int function(const int src[16])
{
    int val1 = 0;
    int dst[16] = {0};
    int val2 = 0;
    const int *psrc = src;
    /*当数组作为函数参数传递时，它会被退化为指针，
    因此 sizeof 运算符返回的是指针的大小，而不是数组的大小。*/
    fprintf(stdout, "size of src = %lu\n", sizeof(src));
    /*局部变量的入栈顺序：先声明的先入栈，同时数组作为整体，
    其地址是向上增长的，将val1覆盖了*/
    for (int i = 0; i <= 16; i++)
    {
        dst[i] = *psrc + i;
        psrc++;
    }
    return 0;
}
int main()
{
    const int src[16] = {0};
    printf("%d\n", sizeof(src));
    fprintf(stdout, "size of src = %lu\n", sizeof(src));
    function(src);
    return 0;
}