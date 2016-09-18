#include <stdio.h>

int power(int base, int n)
{
    int p = 1;
    for (int i = 1; i <= n; ++i)
        p *= base;
    return p;
}

main()
{
    for (int i = 0; i < 10; ++i)
        printf("%d\t%3d\t%6d\n", i, power(2, i), power(-3, i));
}
