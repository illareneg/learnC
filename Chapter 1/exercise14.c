#include <stdio.h>

#define FREQUENCIES_LENGTH 52

main()
{
    int frequencies[FREQUENCIES_LENGTH], i;
    
    for (i = 0; i < FREQUENCIES_LENGTH; ++i)
        frequencies[i] = 0;

    int c;
    while ((c = getchar()) != EOF)
        if (c >= 'A' && c <= 'Z')
            ++frequencies[c - 'A'];
        else if (c >= 'a' && c <= 'z')
            ++frequencies[c - 'a' + FREQUENCIES_LENGTH/2];

    int j = 0;

    for (i = 0; i < FREQUENCIES_LENGTH/2; ++i)
    {
        printf("%c ", i + 'A');
        for (j = 0; j < frequencies[i]; ++j)
            putchar('#');
        putchar('\n');
    }
   
    for (; i < FREQUENCIES_LENGTH; ++i)
    {    
        printf("%c ", i + 'a' - FREQUENCIES_LENGTH/2);
        for (j = 0; j < frequencies[i]; ++j)
            putchar('#');
        putchar('\n');
    }
}
