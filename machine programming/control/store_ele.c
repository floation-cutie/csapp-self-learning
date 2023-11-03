#include <stdio.h>
#include <stdlib.h>
#define R 7
#define S 5
#define T 13
long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}
int main()
{
    A[1][1][1] = 10;
    long *dest = malloc(sizeof(long));
    printf("%ld\n", store_ele(1, 1, 1, dest));
    printf("%ld\n", *dest);
    system("pause");
    return 0;
}