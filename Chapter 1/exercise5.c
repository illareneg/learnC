#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

main()
{
    printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
    for (int fahr = UPPER, celsius; fahr >= LOWER; fahr -= STEP)
        printf("%10d\t%9.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
