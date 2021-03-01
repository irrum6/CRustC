#include <stdio.h>

int findCubes(unsigned int n);
int main()
{

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
    return 0;
}

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
                        printf("cubes:\n", cube);
                        printf("%d,%d,%d,%d\n", i, j, k, l);
                    }
                }
            }
        }
    }
    return count;
}
// I feel stupid
