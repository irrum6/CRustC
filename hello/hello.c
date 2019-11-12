#include <stdio.h>

#ifndef __cplusplus
typedef char bool;
#define true 1
#define false 0
#endif

int printHello(char name[], bool usename);

int main()
{
    char *name = {"mindora"};
    char name1[] = "irakli";

    char *name2 = {"ირაკლი"};

    printHello(name, false);
    printHello(name, true);
    printHello(name1, false);
    printHello(name1, true);
    printHello(name2, true);
    return 0;
}

int printHello(char name[], bool usename)
{
    if (usename)
    {
        printf("hello,%s!\n", name);
        return 1;
    }
    printf("Hello, World!\n");
    return 2;
}