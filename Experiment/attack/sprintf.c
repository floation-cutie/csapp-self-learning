#include <stdio.h>
#include <stdlib.h>
int main()
{
    char buffer[100];
    int number = 42;
    float floatNumber = 3.14;

    // 使用 sprintf 将格式化的数据写入字符串
    int written = sprintf(buffer, "The number is %d and the float is %.2f", number, floatNumber);

    // 打印写入字符的总数和字符串内容
    printf("Written characters: %d\n", written);
    printf("Formatted string: %s\n", buffer);
    int val = 255;
    char *s = (char *)malloc(sizeof(char) * 10);
    sprintf(s, "%.8x", val);
    printf("%s\n", s);
    system("pause");
    return 0;
}
