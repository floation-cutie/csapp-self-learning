#include <stdio.h>

/* 没有最大输入字节上界的限制，可能破坏
    1. 未被使用的栈空间
    2. 返回地址
    3. caller中保存的寄存器，局部变量等状态*/
char *gets(char *s)
{
    int c;
    char *dest = s;
    while ((c = getchar()) != '\n' && c != EOF)
        *dest++ = c;
    if (c == EOF && dest == s)
    {
        /* 表示没有字节读入*/
        return NULL;
    }
    *dest++ = '\0';
    return s;
}
void echo()
{
    char buf[8];
    gets(buf);
    puts(buf);
}