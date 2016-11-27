#include <stdio.h>

// assume s2 is large enough

void expand(const char *s1, char *s2)
{
    int end, i;

    do {
        end = 0;
        if (*s1 >= '0' && *s1 <= '9')
            while (*(s1 + end + 1) == '-' && *s1 < *(s1 + end + 2) && *(s1 + end + 2) <= '9')
                end += 2;
        else if (*s1 >= 'a' && *s1 <= 'z')
            while (*(s1 + end + 1) == '-' && *s1 < *(s1 + end + 2) && *(s1 + end + 2) <= 'z')
                end += 2;
        else if (*s1 >= 'A' && *s1 <= 'Z')
            while (*(s1 + end + 1) == '-' && *s1 < *(s1 + end + 2) && *(s1 + end + 2) <= 'Z')
                end += 2;
        for (i = 0; *s1 + i <= *(s1 + end); ++i)
            *s2++ = *s1 + i;
        s1 += end + 1;
    } while (*s1);
}
