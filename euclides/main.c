#include <stdio.h>
#include <stdbool.h>

int findGCD(int a, int b);
bool test(void);

int main()
{
    char *testmsg = test() ? "success." : "fail";
    printf("%s\n", testmsg);
    int a = 0, b = 0;
    printf("enter number \n");
    scanf("%d", &a);
    printf("enter number \n");
    scanf("%d", &b);
    printf("Greatest Commond Divisor is %d\n", findGCD(a, b));
    return 0;
}

int findGCD(int a, int b)
{
    if (a < b)
        return findGCD(b, a);
    int rem = b;
    while (rem != 0)
    {
        rem = a % b;
        if (rem == 0)
            continue;
        a = b;
        b = rem;
    }
    return b;
}

bool test(void)
{
    //use primes to test
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    const int total = 10;

    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            int m1 = primes[i] * primes[j];
            int m2 = primes[j] * primes[j];
            if (findGCD(m1, m2) != primes[j])
            {
                return false;
            }
        }
    }
    return true;
}