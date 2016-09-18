#include <stdio.h>

main()
{
    int lower, upper = 300, step = 20;
    float celsius, fahrenheit;

    printf("%10s\t%10s\n", "Celsius", "Fahrenheit");
    while (fahrenheit <= upper)
    {
        fahrenheit = celsius*9.0/5.0 + 32.0;
        printf("%10.0f\t%10.0f\n", celsius, fahrenheit);
        celsius += step;
    }    
}
