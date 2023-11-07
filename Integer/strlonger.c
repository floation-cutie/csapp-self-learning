#include <stdio.h>
#include <string.h>

// buggy function
int strlonger(char *s, char *t)
{
    // when s的长度小于t的长度,负数转换成无符号数
    return strlen(s) - strlen(t) > 0;
    //the following one is correct!
    return strlen(s) > strlen(t);
}