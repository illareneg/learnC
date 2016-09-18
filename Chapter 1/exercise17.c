#include <stdio.h>

#define MAX_SIZE 1000

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    char s[MAX_SIZE];
    int len;

    while ((len = get_line(s, MAX_SIZE)) > 0)
        if (len > 80)
            printf("%s\n", s);

    return 0;
}
