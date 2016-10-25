#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hdtoi(const char hd)
{
    int i = -1;

    char hd_lower = tolower(hd);
    if (isdigit(hd_lower))
        i = hd_lower - '0';
    else if (hd_lower >= 'a' && hd_lower <= 'f')
        i = hd_lower - 'a' + 10;
    return i;
}

// Assume positive values
int htoi(const char *h)
{
    int i = 0, curr, len;

    if (*h == '0' && (*(h + 1) == 'x' || *(h + 1) == 'X'))
        h += 2;
    len = strlen(h);
    for (int j = 0; j < len; ++j) {
        curr = hdtoi(*(h + j));
        if (curr != -1) 
            i += pow(16, len - 1 - j)*curr;
        else {
            fprintf(stderr, "Non-hexadecimal char: %c\n", *(h + j));
            i = -1;
            break;
        }
    }
    return i;
}

main()
{
    printf("%d %d %d\n", htoi("AA"), htoi("0xFAA"), htoi("0XC30"));
}
