#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void copyij(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for (int i = 0; i < 2048; i++)
    {
        for (int j = 0; j < 2048; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

void copyji(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for (int j = 0; j < 2048; j++)
    {
        for (int i = 0; i < 2048; i++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

int main()
{
    int(*src)[2048] = malloc(sizeof(int[2048][2048]));
    int(*dst)[2048] = malloc(sizeof(int[2048][2048]));
    for (int j = 0; j < 2048; j++)
        for (int i = 0; i < 2048; i++)
            src[i][j] = 1;
    clock_t start, end;
    start = clock();
    copyji(src, dst);
    end = clock();
    double runtime = 1.0 * (end - start) / CLOCKS_PER_SEC;
    printf("the runtime is %lf seconds\n", runtime);
    free(src);
    free(dst);
    return 0;
}
