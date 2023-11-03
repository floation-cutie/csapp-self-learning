#include <stdio.h>
#include <stdlib.h>
#define CNT 20
typedef struct
{
    long idx;
    long x[4];
} a_struct;

typedef struct
{
    int first;
    a_struct a[CNT];
    int last;
} b_struct;

void test(long i, b_struct *bp)
{
    int n = bp->first + bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

int main()
{
    b_struct *bp = malloc(sizeof(b_struct));
    bp->first = 2;
    bp->last = 20;
    bp->a[1].idx = 1;
    test(1, bp);
    printf("%ld\n", bp->a[1].x[1]);
    system("pause");
    return 0;
}