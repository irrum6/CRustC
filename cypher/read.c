#include <stdio.h>

int stdReadLine(int min, int max, char to[])
{
    char ch;
    int read = 0;
    while (ch != '\n' /*&& ch != EOF*/)
    {
        ch = getchar();
        //fear newline, and discard excess chars
        if (ch == '\n' || ch == '\0' || read >= max)
        {
            continue;
        }
        to[read] = ch;
        read++;
    }
    if (read < min)
    {
        printf("couldn\'t read enough characters\n");
        return -1;
    }
    to[read + 1] = '\0'; //terminate string;
    return read;
}