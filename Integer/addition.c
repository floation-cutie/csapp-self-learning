// determine whether arguments can be added without overflow if the return val is 1
int uadd_ok(unsigned x, unsigned y)
{
    unsigned sum = x + y;
    return sum >= x;
}

// consider 无符号加法逆元 即模运算下的0 等价于2的w次方

// determine whether arguments can be added without overflow if the return val is 1
// 描述两种为0的情形
int tadd_ok(int x, int y)
{
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x > 0 && y > 0 && sum < 0;
    return !neg_over && !pos_over;
}

// the code is buggy
// 补码的和构成阿贝尔群,故无论有无溢出,他们的求值总为 y==y && x==x 返回值总为true
int tadd_notok(int x, int y)
{
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}