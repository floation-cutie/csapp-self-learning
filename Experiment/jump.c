#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int tree[40] =
    {-1, 36, 8, 50, 6, 22, 45, 107, 1, 7, 20, 35, 40, 47, 99, 1001};
int cur = 1;
int esi = 47;
int eax;
void find()
{
    if (tree[cur] == -1)
    {
        eax = 0x3f3f3f3f;
        return;
    }

    if (tree[cur] <= esi)
    {
        eax = 0;
        if (tree[cur] == esi)
            return;
        else
        {
            cur = 2 * cur + 1;
            find();
            eax = 2 * eax + 1;
            return;
        }
    }
    else
    {
        cur = 2 * cur;
        find();
        eax = 2 * eax;
        return;
    }
}
int main()
{
    eax = esi - 1;
    for (int i = 0; i < 40; i++)
        if (tree[i] <= 0)
            tree[i] = -1;
    find();
    if (eax == 5)
    {
        puts("FIND it!!!!");
    }
}
