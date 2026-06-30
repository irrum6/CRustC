#include <stdio.h>
#include <stdbool.h>

int findCubes(unsigned int n)
{
    //find and print every a,b,c,d < n
    //where a^3+b^3= c^3+ d^3
    int count = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            unsigned int cube = (i * i * i) + (j * j * j);
            for (unsigned int k = 0; k < n; k++)
            {
                for (unsigned int l = 0; l < n; l++)
                {
                    if (k == l || k == i || k == j)
                        continue;
                    unsigned int cube2 = (k * k * k) + (l * l * l);
                    if (cube2 == cube)
                    {
                        count++;
                        printf("cubes:%d\n", cube);
                        printf("%d,%d,%d,%d\n", i, j, k, l);
                    }
                }
            }
        }
    }
    return count;
}

void run_cubes(){
    const unsigned int MAX = 1000;
    unsigned int num = 0;
    printf("enter number between 1 and %d\n", MAX);
    scanf("%d", &num);
    if (num > MAX)
    {
        printf("maxed\n");
        num = MAX;
    }
    int found = findCubes(num);
    printf("Found %d such numbers",found);
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

bool test_gcd(void)
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

int run_gcd()
{
    char *testmsg = test_gcd() ? "success." : "fail";
    printf("%s\n", testmsg);
    int a = 0, b = 0;
    printf("enter number \n");
    scanf("%d", &a);
    printf("enter number \n");
    scanf("%d", &b);
    printf("Greatest Commond Divisor is %d\n", findGCD(a, b));
    return 0;
}

int ops()
{
    int a = 3;
    int b = 4;
    int c = 5;
    int d = a + b - (a < b); //a<b is true is 1 (one)
    int e = (a > b) - a;     // a>b is false is 0 (zero)
    int f = (a > b) * b;     // a>b is false is 0 (zero)
    printf("a:%d,b:%d,c:%d,d:%d,e:%d,f:%d\n", a, b, c, d, e, f);
    a = 4;
    b = 5;
    c = 6;
    d = a + b + (a != b);
    e = a + b * (a == b); // a==b is false is 0 b*0 is 0 result is 4
    f = a * b - (a <= b);
    printf("a:%d,b:%d,c:%d,d:%d,e:%d,f:%d\n", a, b, c, d, e, f);
    //logical operators
    a = 5;
    b = 6;
    c = 7;
    d = (a > b);
    e = (a < b);
    f = d || e && (d || e);
    printf("a:%d,b:%d,c:%d,d:%d,e:%d,f:%d\n", a, b, c, d, e, f);
    f = e || d && (d || e); //hmm
    printf("a:%d,b:%d,c:%d,d:%d,e:%d,f:%d\n", a, b, c, d, e, f);

    return 0;
}

void swap(int *a, int *b){
    *a= *a ^ *b;
    *b = *a ^ *b;
    *a= *a ^ *b;
}

int run_swap()
{
    int a = 69;
    int b = 72;
    printf("swap example using binary or\n");
    printf("a is %d, b is %d \n", a, b);
    printf("------swap------\n");
    swap(&a, &b);
    printf("a is %d, b is %d \n", a, b);
    return 0;
}