#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

double fahrenheit_to_celsius(double fahrenheit)
{
    return 5.0/9*(fahrenheit - 32);
}

main()
{
    printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
    for (int fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP)
        printf("%10d\t%9.1f\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
}
