#include <stdio.h>

main()
{
    double num_blank, num_tab, num_newline;

    int c;
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++num_blank;
        else if (c == '\t')
            ++num_tab; 
        else if (c == '\n')
            ++num_newline;

    printf("blanks: %.0f, tabs: %.0f, newlines: %.0f\n", num_blank, num_tab, num_newline);
}
