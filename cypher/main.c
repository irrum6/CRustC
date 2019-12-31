#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "read.h"
#include "cypher.h"

void writeMenu();
bool matches(char *str1, char *str2, int len);
void actOnCommand(char *command);

int main()
{
    writeMenu();
    char command[9];
    bool notExit = true;
    while (!matches(command, "exit", 4))
    {
        int res = stdReadLine(3, 9, command);
        if (res < 0)
        {
            printf("short, type again\n");
            continue;
        }
        printf("%s\n", command);
        actOnCommand(command);
    }
    return 0;
}

void writeMenu()
{
    printf("commands available:\n");
    printf("cypher - encrypt text with key\n");
    printf("decypher -decrypt text with key\n");
    printf("help - displays this menu\n");
}
bool matches(char *str1, char *str2, int len)
{
    if (len < 0)
        return false;
    return (strncmp(str1, str2, len) == 0);
}
void actOnCommand(char *command)
{
    if (matches(command, "help", 4))
    {
        writeMenu();
    }
    if (matches(command, "cypher", 6))
    {
        onCrypt(true);
    }
    if (matches(command, "decypher", 8))
    {
        onCrypt(false);
    }
    return;
}