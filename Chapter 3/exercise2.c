#include <stdio.h>

// assume s's large enough

void escape(char *s, char *t)
{
    do
        switch (*t) {
        case '\a':
            *s++ = '\\';
            *s++ = 'a';
            break;
        case '\b':
            *s++ = '\\';
            *s++ = 'b';
            break;
        case '\f':
            *s++ = '\\';
            *s++ = 'f';
            break;
        case '\n':
            *s++ = '\\';
            *s++ = 'n';
            break;
        case '\r':
            *s++ = '\\';
            *s++ = 'r';
            break;
        case '\t':
            *s++ = '\\';
            *s++ = 't';
            break;
        case '\v':
            *s++ = '\\';
            *s++ = 'v';
            break;
        default:
            *s++ = *t;
        }
    while (*t++);
}

void unescape(char *t, char *s)
{
    while (*s)
        if (*s == '\\')
            switch (*(s + 1)) {
            case 'a':
                *t++ = '\a';
                s += 2;
                break;
            case 'b':
                *t++ = '\b';
                s += 2;
                break;
            case 'f':
                *t++ = '\f';
                s += 2;
                break;
            case 'n':
                *t++ = '\n';
                s += 2;
                break;
            case 'r':
                *t++ = '\r';
                s += 2;
                break;
            case 't':
                *t++ = '\t';
                s += 2;
                break;
            case 'v':
                *t++ = '\v';
                s += 2;
                break;
            default:
                *t++ = '\\';
                ++s;
            }
        else
            *t++ = *s++;
}
