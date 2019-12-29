#include <stdio.h>

void findCubes(unsigned int n);
int main()
{

    const int MAX = 1000;
    int num = 0;
    printf("enter number between 1 and %d\n", MAX);
    scanf("%d", &num);
    if (num > MAX)
    {
        printf("maxed\n");
        num = MAX;
    }
    findCubes(num);
    return 0;
}

void findCubes(unsigned int n)
{
    //find and print every a,b,c,d < n
    //where a^3+b^3= c^3+ d^3
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
                        printf("cubes:\n", cube);
                        printf("%d,%d,%d,%d\n", i, j, k, l);
                    }
                }
            }
        }
    }
}
// I feel stupid
