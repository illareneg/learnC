#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
    int c, i, len, state;
    c = i = len = state = 0;
    while ((c = getchar()) != EOF)
    {
        if (state == IN && (c == ' ' || c == '\t' || c == '\n'))
        {
            for (i = 0; i < len; ++i)
                putchar('#');
            putchar('\n');
            len = 0;
            state = OUT;
        }
        else
        {
            if (state == OUT)
                state = IN;
            ++len;
        }
    }
}
