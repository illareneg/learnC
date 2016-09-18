#include <stdio.h>

#define SIZE 1000

int get_line(char s[], int lim)
{
    char c;
    int i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[], int size)
{
    char t;
    
    for (int i = 0; i < size/2; ++i) {
        t = s[i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = t;
    }
}

int main()
{
    char input[SIZE];
    int length;
    
    while ((length = get_line(input, SIZE)) > 0) {
        reverse(input, length);
        printf("%s\n", input);
    }
    return 0;
}
