#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n)
{
    int low = 0, mid, high = n - 1;
    
    while (low <= high) {
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low = 0, mid, high = n - 1;

    while (low <= high && x != v[mid]) {
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return x == v[mid] ? mid : -1;
}

#define SIZE 1000000

main()
{
    int v[SIZE], result;
    clock_t begin;
    clock_t end;

    for (int i = 0; i < SIZE; ++i)
        v[i] = i;
    begin = clock();
    result = binsearch(0, v, SIZE);
    end = clock();
    printf("%sfound\n", result == 0 ? "" : "not ");   
    printf("binsearch time (N:%d): %f seconds\n", SIZE, (double)(end - begin)/CLOCKS_PER_SEC);   
    begin = clock();
    result = binsearch2(0, v, SIZE);
    end = clock();
    printf("%sfound\n", result == 0 ? "" : "not ");   
    printf("binsearch2 time (N:%d): %f seconds\n", SIZE, (double)(end - begin)/CLOCKS_PER_SEC);
}
