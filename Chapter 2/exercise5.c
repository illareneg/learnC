#include <stdbool.h>
#include <stdio.h>

bool contains(const char *s, const char c)
{
    bool ret = false;
    
    while (*s != '\0') {
        if (*s++ == c) {
            ret = true;
            break;
        }
    }
    return ret;
}

int any(const char *s, const char *s2)
{
    int ret = -1;

    for (int i = 0; s[i] != '\0'; ++i)
        if (contains(s2, s[i])) {
            ret = i;
            break;
        }
    return ret;
}

main()
{
    printf("%d\n", any("onetwothree", "r"));
    printf("%d\n", any("onetwothree", "x"));
}
