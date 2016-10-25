#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    return x&((((~0 << n)|y) << (p + 1 - n))|~(~0 << (p + 1 - n)));
}
