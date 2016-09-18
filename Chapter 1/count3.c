#include <stdio.h>

main()
{
    int n1 = 0;
    
    int c;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
    
    printf("%d\n", n1);
}
