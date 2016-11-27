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

// assume n >= 0 && n <= 15
char itoc(int n)
{
    char c = '\0';

    if (n >= 0 && n <= 9)
        c = n + '0';
    else if (n <= 15)
        switch (n) {
            case 10:
                c = 'A';
                break;
            case 11:
                c = 'B';
                break;
            case 12:
                c = 'C';
                break;
            case 13:
                c = 'D';
                break;
            case 14:
                c = 'E';
                break;
            case 15:
                c = 'F';
                break;
        }
    
    return c;
}

void itob(int n, char *s, int b)
{
    int i = 0, sign = n;
    
    if (sign < 0)
        n = -n;
    do
        s[i++] = itoc(n%b);
    while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

main()
{
    char s[1000];
    
    itob(105, s, 16);
    printf("%s\n", s);
}
