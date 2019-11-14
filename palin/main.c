#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

short is_exit(char s[])
{
    return (s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't') ? 1 : 0;
    //return (0==strcmp(s,"exit"))?1:0;
}
bool is_palindrome(char word[], short len);

int main()
{
    short str_size = 20;
    char str[str_size];
    //short iterato
    short i = 0;
    while (true)
    {
        printf("Type word , max %d characters\n", str_size);
        fgets(str, str_size, stdin);
        short len = strlen(str) - 1; //without null \0 terminator
        //is exit?
        if (is_exit(str))
        {
            break;
        }
        if (is_palindrome(str, len))
        {
            printf("Palindrome\n");
        }
        else
        {
            printf("Not a palindrome\n");
        }
    }
    return 0;
}

bool is_palindrome(char word[], short len)
{
    //short iterator
    short i = 0;
    i = 0;
    while (i < len - 1)
    {
        i++;
        if (word[i] != word[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}