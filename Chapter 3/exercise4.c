#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char *s)
{
    char t;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itoa(int n, char *s)
{
    int i, sign, is_twos_comp_min_negative = 0;

    if ((sign = n) < 0)
        n = -n;
    if (n < 0) {
        is_twos_comp_min_negative = 1;
        n -= 1;
    }
    i = 0;
    do {
        s[i++] = n%10 + '0';
    } while ((n /= 10) > 0);
    if (is_twos_comp_min_negative)
        ++s[0];
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
