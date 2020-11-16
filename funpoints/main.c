#include <stdio.h>
#include <stdlib.h>

void print_fun(void (*fun)(int),int x){
    printf("have fun ");
    fun(x);
}

void print_int (int a){
    printf("%d times\n",a);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        void (*pf)(int);
        pf = print_int;
       print_fun(*pf, argc);
    }

    return 0;
}