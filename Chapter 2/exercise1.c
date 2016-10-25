#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    // Assume circular over/underflow
    char schar_min = -1, schar_max = 1;
    unsigned char uchar_max = -1;
    short shrt_min = -1, shrt_max = 1;
    unsigned short ushrt_max = -1;
    int int_min = -1, int_max = 1;
    unsigned int uint_max = -1;
    long long_min = -1, long_max = 1;
    unsigned long ulong_max = -1;

    printf("system ranges from headers\n");
    printf("signed char range: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range: %u - %u\n", 0u, UCHAR_MAX);
    printf("signed short range: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short range: %u - %u\n", 0u, USHRT_MAX);
    printf("signed int range: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: %u - %u\n", 0u, UINT_MAX);
    printf("signed long range: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long range: %lu - %lu\n", 0ul, ULONG_MAX);
    while (--schar_min < 0)
        ;
    ++schar_min;
    while (++schar_max > 0)
        ;
    --schar_max;
    while (--shrt_min < 0)
        ;
    ++shrt_min;
    while (++shrt_max > 0)
        ;
    --shrt_max;
    while (--int_min < 0)
        ;
    ++int_min;
    while (++int_max > 0)
        ;
    --int_max;
    while (--long_min < 0)
        ;
    ++long_min;
    while (++long_max > 0)
        ;
    --long_max;
    printf("computed system ranges\n");
    printf("signed char range: %d - %d\n", schar_min, schar_max);
    printf("unsigned char range: %u - %u\n", 0u, uchar_max);
    printf("signed short range: %d - %d\n", shrt_min, shrt_max);
    printf("unsigned short range: %u - %u\n", 0u, ushrt_max);
    printf("signed int range: %d - %d\n", int_min, int_max);
    printf("unsigned int range: %u - %u\n", 0u, uint_max);
    printf("signed long range: %ld - %ld\n", long_min, long_max);
    printf("unsigned long range: %lu - %lu\n", 0ul, ulong_max);
    return 0;
}
