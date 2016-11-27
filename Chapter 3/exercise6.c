#include <stdio.h>

// assume s is large enough & b >= 2 && b <= 16

unsigned strlen(char *s)
{
    unsigned len = 0;

    while (*s++)
        ++len;
    return len;
}

void reverse(char *s)
{
    char t;

    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itoa(int n, char *s, int w)
{
    int i = 0, sign = n;
    
    if (sign < 0)
        n = -n;
    do
        s[i++] = n%10 + '0';
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

main()
{
    char s[1000];
    
    itoa(105, s, 7);
    printf("%s\n", s);
}
