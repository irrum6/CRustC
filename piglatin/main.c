#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//is this a consonant?
short is_vowel(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')?1:0;
}
//is this a brexit?
short is_exit(char s[])
{
    return (s[0]=='e'&&s[1]=='x'&&s[2]=='i'&&s[3]=='t')?1:0;
}

int main()
{
    short s_size=20;
    char s[s_size];
    short vowel_index=0;
    short not_to_stop=1;
    while(not_to_stop)
    {
        printf("type word, max(20 characters)\n");
        printf("type exit to exit\n");
        long len=strlen(fgets(s,s_size,stdin))-1;
        if(is_exit(s))
        {
            not_to_stop=0;
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
    return 0;
}
