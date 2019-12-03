#include <stdio.h>
#include <stdlib.h>

struct _result
{
    int errors;
    int result;
};

typedef struct _result result;

result *calculate(char op, int a, int b)
{
    result *res = (result *)malloc(sizeof(result));
    res->errors = 0;
    res->result = 0;

    char *ops = "+-*/";

    if (op != ops[0] && op != ops[1] && op != ops[2] && op != ops[3])
    {
        //operator not supported;
        res->errors = -1;
        return res;
    }

    if (op == '+')
        res->result = a + b;

    if (op == '-')
        res->result = a - b;
    if (op == '*')
        res->result = a * b;
    if (op == '/')
        res->result = a / b;
    return res;
}

int main(int argc, char **argv)
{
    int i = 0;

    printf("all param count : %d\n", argc);

    if (argc < 4)
    {
        printf("not enough parameters passed\n");
        return -2;
    }

    char op = argv[2][0]; //first char of second argument
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);

    result *rs = calculate(op, a, b);

    printf("expression was :%s%s%s \n", argv[1], argv[2], argv[3]);

    printf("errors: %d, result: %d\n", (rs->errors), rs->result);

    return 0;
}