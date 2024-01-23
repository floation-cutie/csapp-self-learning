#include <stdio.h>
int main()
{
    int cnt = 0;
    for (int a = -8; a <= 8; a++)
    {
        int x = a >> 2;
        int y = (x + a) / 4;
        if (x == y)
        {
            printf("%d ", a);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}