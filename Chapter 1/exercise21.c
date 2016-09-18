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

int is_blanks(char s[])
{
    int ret = 1;
   
    while (*s != '\0')
        if (*s++ != ' ') {
            ret = 0;
            break;
        }
    return ret;
}

void print_entab(char s[], int len) {
    int ntab = len/TAB_SIZE;
    int nblank = len%TAB_SIZE;
    int i;
    
    for (i = 0; i < ntab; ++i)
        putchar('\t');
    for (i = 0; i < nblank; ++i)
        putchar(' ');
}

main()
{
    char s[SIZE];
    int len;

    while ((len = get_line(s, SIZE)) > 0)
        if (is_blanks(s)) {
            print_entab(s, len);
            putchar('\n');
        }
        else
            printf("%s\n", s);
}
