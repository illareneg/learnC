#include <stdio.h>

#define UNSIGNED_BITS (sizeof(unsigned)*8)

unsigned rightrot(unsigned x, unsigned n)
{
    unsigned effective_n = n%UNSIGNED_BITS;
    return (x >> effective_n)|(x << (UNSIGNED_BITS - effective_n));
}

main()
{
    printf("%u\n", rightrot(511u, 3u));
}
