#include <stdio.h>
#define ZLEN 5
typedef int zip_dig[ZLEN];
// to avoid the existence of magic num
int main()
{
    zip_dig cmu = {31242, 2, 3, 4, 31241};
    printf("%p", **cmu); // will not compile
}