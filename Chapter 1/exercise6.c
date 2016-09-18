#include <stdio.h>

main()
{
    int c;
    do
    {
        c = getchar() != EOF;
        printf("getchar() != EOF is %d\n", c);
    }
    while (c);
}
