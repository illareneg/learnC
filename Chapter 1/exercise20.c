#include <stdio.h>

#define SIZE     1001
#define TAB_SIZE 8

int get_line(char s[], int max_len)
{
    int i;
    char c;

    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int spaces_to_next_tabstop(int i)
{
    return TAB_SIZE - i%TAB_SIZE;
}

void print_detab(char s[], int sz)
{
    for (int i = 0, j = 0, k, spaces; i < sz; ++i, ++j)
        if (s[i] == '\t') {
            spaces = spaces_to_next_tabstop(j);
            for (k = 0; k < spaces; ++k)
                putchar(' ');
            j += spaces - 1;
        }
        else
            putchar(s[i]);
}

main()
{
    char s[SIZE];
    int len;

    while ((len = get_line(s, SIZE)) > 0)
        print_detab(s, len);
}
