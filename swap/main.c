#include <stdio.h>
#include "swap.h"

int main()
{
    int a = 69;
    int b = 72;
    printf("a is %d, b is %d \n", a, b);
    printf("------swap------\n");
    swap(&a, &b);
    printf("a is %d, b is %d \n", a, b);
    return 0;
}