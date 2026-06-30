typedef struct 
{
    int errors;
    int result;
} Result;

Result* calculate(char op, int a, int b);

int run_args(int argc, char **argv);