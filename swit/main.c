#include <stdio.h>
#include <stdbool.h>

int strangeFun(int a);
bool test(int vars[], int vars_size, int exp[], int exp_size);

int main(int argc, char **argv)
{
    int par_size = 11;
    int exp_size = 11;
    int params[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected_results[11] = {16, 2, 10, 11, 12, 13, 14, 15, 16, 9, 12};

    bool success = test(params, par_size, expected_results, exp_size);

    if (success)
    {
        printf("test succeeded.\n");
    }
    else
    {
        printf("test didn\'t succeed.\n");
    }
}

bool test(int vars[], int vars_size, int exp[], int exp_size)
{
    if (vars_size != exp_size)
    {
        printf("lengths don't match.");
        return false;
    }

    for (int i = 0; i < vars_size; i++)
    {
        if (strangeFun(vars[i]) != exp[i])
        {
            return false;
        }
    }
    return true;
}

int strangeFun(int a)
{
    switch (a)
    {
    case 0:
        a = 16;
        break;
    case 1:
        a++;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        a += 8;
        break;
    case 9:
        break;
    default:
        a += 2;
        break;
    }
    return a;
}