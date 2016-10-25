#include <stdbool.h>
#include <stdio.h>

bool contains(const char *s, const char c)
{
    bool ret  = false;

    while (*s != '\0')
        if (*s++ == c) {
            ret = true;
            break;    
        }
    return ret;
}

void squeeze(char *s, const char *c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i)
        if (!contains(c, s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

main()
{
    char s[] = "onetwothree";
    squeeze(s, "oe");
    printf("%s\n", s); 
}
