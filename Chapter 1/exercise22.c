#include <stdio.h>

#define SIZE                 1000
#define MAX_COLUMNS_PER_LINE 80

int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int index_of_last_nonblank(char s[], int len)
{
    int i;

    for (i = len - 1; i >= 0; --i)
        if (s[i] != ' '
}

void print_fold(char s[])
{
    char s2[MAX_COLUMNS_PER_LINE]
    int column = 0;

    while (*s != '\0') {
        if (column == MAX_COLUMNS_PER_LINE) {
            column = 0;
            putchar
        }
        putchar(*s);
        ++column;
    }
}

main()
{
    char s[SIZE];

    while (get_line(s, SIZE) > 0)
        print_fold(s);
}
