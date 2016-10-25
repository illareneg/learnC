#include <stdio.h>

char lower(const char c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;    
}

main()
{
    char s[] = "CAPITAL";
    for (int i = 0; s[i] != '\0'; ++i)
        s[i] = lower(s[i]);
    printf("%s\n", s);
}
