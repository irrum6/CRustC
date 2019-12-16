#include <stdio.h>

void fizzBuzz(int i);
int main(int argc, char **argv)
{
    int num;
    printf("type number\n");
    scanf("%d", &num);
    fizzBuzz(num);
    return 0;
}

void fizzBuzz(int num)
{
    if (num % 15 == 0)
    {
        printf("FizzBuzz\n");
        return;
    }
    if (num % 3 == 0)
    {
        printf("Fizz\n");
        return;
    }
    if (num % 5 == 0)
    {
        printf("Buzz\n");
        return;
    }
    printf("%d\n", num);
}