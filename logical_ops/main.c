#include <stdio.h>

int main()
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
    e = a + b * (a == b);// a==b is false is 0 b*0 is 0 result is 4
    f = a * b - (a <= b);
    printf("a:%d,b:%d,c:%d,d:%d,e:%d,f:%d\n", a, b, c, d, e, f);
    return 0;
}