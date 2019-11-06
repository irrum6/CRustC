#include <stdio.h>

void printHello(char name[]);

int main()
{
    char *name = {"mindora"};
    char name1[] = "irakli";
    printHello(name);
    printHello(name1);
    return 0;
}

void printHello(char name[])
{
    printf("hello,%s\n", name);
}