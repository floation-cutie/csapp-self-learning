#include <stdio.h>
#include <stdlib.h>
// 作为全局变量
int ret = 0;
int cnt = 1;
int func4(int findVal, int low, int high)
/* findVal is in edi, low is in esi, high is in edx*/
{
    int region = high - low;
    int sign = region >> 31;

    region = (region + sign) >> 1;
    int mid = region + low;
    if (mid > findVal)
    {
        func4(findVal, low, mid - 1);
        ret += mid;

        printf("time %d ,add %d\n", cnt, mid);
        cnt++;
    }
    else
    {
        ret = mid;
        if (mid == findVal)
        {
            printf("the initial value is %d\n", mid);
            return ret;
        }
        else
        {
            func4(findVal, mid + 1, high);
            ret += mid;
            printf("time %d ,add %d\n", cnt, mid);
            cnt++;
        }
    }
    return ret;
}

void test(int res, int ans)
{
    if (res == ans)
        puts("We did it");
}
int main()
{
    int a;
    scanf("%d", &a);
    int res = func4(a, 0, 14);
    test(res, 13);
    return 0;
}