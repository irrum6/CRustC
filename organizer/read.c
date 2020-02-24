#include <stdio.h>
#include <string.h>

int stdReadLine(int min, int max, char to[])
{
    char ch;
    int read = 0;

    fgets(to, max, stdin);
    printf("read: %s", to);
    if (!strchr(to, '\n'))
    {
        while (fgetc(stdin) != '\n')
        {
        }
    }
    //getchar();
    read = strlen(to);
    if (read < min)
    {
        printf("couldn\'t read enough characters\n");
        return -1;
    }
    return read;
}