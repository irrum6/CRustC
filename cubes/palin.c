#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//is this a brexit?
short is_exit(char s[])
{
    return (s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't') ? 1 : 0;
    //return (0==strcmp(s,"exit"))?1:0;
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

void run_palindrome()
{
    short str_size = 20;
    char str[str_size];
    //short iterato
    short i = 0;

    printf("Type exit to exit \n");

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

}

//is this a consonant?
short is_vowel(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')?1:0;
}

void run_piglatin()
{
    short s_size=20;
    char s[s_size];
    short vowel_index=0;
    short not_to_stop=1;
    
    while(not_to_stop)
    {
        printf("type word, max(20 characters)\n");
        printf("type exit to exit\n");

        long len = strlen(fgets(s,s_size,stdin))-1;
        
        if(is_exit(s))
        {
            not_to_stop = 0;
        }
        short i=0;
        for(; i<s_size; i++)
        {
            if(is_vowel(s[i]))
            {
                vowel_index=i;
                break;
            }
        }

        for(i=vowel_index; i<len; i++)
        {
            printf("%c",s[i]);
        }

        for(i=0; i<vowel_index; i++)
        {
            printf("%c",s[i]);
        }
        switch(vowel_index)
        {
        case 0:
            printf("yay");
            break;
        case 1:
            printf("ay");
            break;
        default:
            printf("ay");
        }
        fputs("\n",stdout);
    }

}
