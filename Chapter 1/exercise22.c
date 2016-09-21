#include <stdio.h>

#define SIZE        1000
#define FOLD_COLUMN 8

int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int first_nullchar_index(char s[], int len)
{
    int i;
    
    for (i = 0; i < len && s[i] != '\0'; ++i)
        ;
    return i;
}

int last_nonblank_index(char s[], int len)
{
    int i;
 
    for (i = first_nullchar_index(s, len) - 1; i >= 0; --i)
        if (s[i] != ' ') {
            ++i;
            break;
        }
    return i;
}

void print_fold(char s[])
{
    int i = 0, next_fold_pos;

    while (s[i] != '\0') {
        next_fold_pos = i + last_nonblank_index(s + i, FOLD_COLUMN);
        while (i < next_fold_pos)
            putchar(s[i++]);
        putchar('\n');
    }
}

main()
{
    char s[SIZE];

    while (get_line(s, SIZE) > 0)
        print_fold(s);
}
