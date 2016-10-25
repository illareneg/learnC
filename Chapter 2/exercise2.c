#include <stdio.h>

int main()
{
    const int lim = 101;
    char s[lim];
    char c;
    int i;

    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        s[i] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
}
