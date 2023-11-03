#include <stdio.h>
#include <stdlib.h>
#define NR(n) (3 * (n))
#define NC(n) (4 * (n) + 1)
/*compute the sum of elements in col j*/
long sum_col(long n, long A[NR(n)][NC(n)], long j)
{
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++)
        result += A[i][j];
    return result;
}

int main()
{
    long A[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            A[i][j] = i + j;
        }
    }
    printf("%ld\n", sum_col(1, A, 2));
    system("pause");
    return 0;
}