#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *str = "12345";
    char *endptr;
    long number = strtol(str, &endptr, 10);

    if (endptr == str)
    {
        printf("No valid digits were found.\n");
    }
    else
    {
        printf("Converted number: %ld\n", number);
    }

    return 0;
}