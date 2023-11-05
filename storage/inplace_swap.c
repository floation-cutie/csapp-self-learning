// implicitly imply that x != y
void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

// when will it crash???
// 我们需要考虑原地交换例程的情形
void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) // from <= to <
    {
        inplace_swap(&a[first], &a[last]);
    }
}