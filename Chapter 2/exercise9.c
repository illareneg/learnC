#include <stdio.h>

unsigned bitcount(unsigned n)
{
    unsigned b;

    for (b = 0; n; n &= n - 1, ++b)
        ;
    return b;
}

main()
{
    printf("%u\n", bitcount(511u));
}
