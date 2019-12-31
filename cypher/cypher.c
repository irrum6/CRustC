#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "read.h"

char replace(char x, char adder);
char extract(char y, char adder);

char *cypher(char *text, char *key, int len, int keylen);
char *decypher(char *text, char *key, int len, int keylen);

void onCrypt(bool encrypt)
{
    const int MAX = 140;
    const int MIN = 3;
    char text[MAX];
    char key[MAX];

    printf("Enter text %d characters or less but at least %d\n", MAX, MIN);
    int len = stdReadLine(MIN, MAX, text);

    getchar();

    printf("Enter key %d characters or less but at least %d\n", MAX, MIN);
    int len2 = stdReadLine(MIN, MAX, key);

    char *encryptedText = NULL;
    if (encrypt)
    {
        encryptedText = cypher(text, key, len, len2);
    }
    else
    {
        encryptedText = decypher(text, key, len, len2);
    }

    printf("%s\n", encryptedText);
    free(encryptedText);
}
char replace(char x, char adder)
{
    const char *supported = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //ignore non alpha chars in text and keys
    if (!isalpha(x) || !isalpha(adder))
        return x;

    int x1 = (int)(strchr(supported, x) - supported); //substract pointer to index from pointer to char
    int adder1 = (int)(strchr(supported, adder) - supported);

    x1 = x1 + adder1;

    if (x1 > 51)
        x1 = x1 - 51;
    return supported[x1];
}
char extract(char y, char adder)
{
    const char *supported = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //ignore non alpha chars in text and keys
    if (!isalpha(y) || !isalpha(adder))
        return y;
    int x1 = (int)(strchr(supported, y) - supported); //substract pointer to index from pointer to char
    int adder1 = (int)(strchr(supported, adder) - supported);

    x1 = x1 - adder1;

    if (x1 < 0)
        x1 = x1 + 51;
    return supported[x1];
}

char *cypher(char *text, char *key, int len, int keylen)
{
    char *ret = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
    {
        int mod = i % keylen;
        char letter = key[mod];
        ret[i] = replace(text[i], letter);
    }
    return ret;
}
char *decypher(char *text, char *key, int len, int keylen)
{
    char *ret = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
    {
        int mod = i % keylen;
        char letter = key[mod];
        ret[i] = extract(text[i], letter);
    }
    return ret;
}