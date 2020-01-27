#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readWordsIntoList(char *list[], const char *restrict fn);
void printList(char *list[], int size);

void sortCharsInString(char *str);
int isUnScrambled(char *a, char *b);

int main()
{
    char *fullList[2048];
    char *sWords[64];
    const char *restrict FILENAME = "words.md";
    const char *restrict FILENAME2 = "list.md";

    int read = readWordsIntoList(sWords, FILENAME);
    int read2 = readWordsIntoList(fullList, FILENAME2);

    // printList(sWords, read);

    for (int i = 0; i < read; i++)
    {
        for (int j = 0; j < read2; j++)
        {
            int compare = isUnScrambled(sWords[i], fullList[j]);
            if (compare == 0)
            {
                printf("%s unscrambled is %s", sWords[i], fullList[j]);
                break;
            }
        }
    }

    return 0;
}

int readWordsIntoList(char *list[], const char *restrict fn)
{
    const char *READ = "r";
    const int MAXLEN = 64;
    char str[MAXLEN];
    FILE *fp = fopen(fn, READ);

    if (fp == 0)
    {
        printf("File can not be opened.");
        return 0;
    }
    int i = 0;
    while (fgets(str, sizeof(str), fp) != 0)
    {
        list[i] = malloc(sizeof(char) * (int)strlen(str));
        strcpy(list[i], str);
        i++;
    }
    fclose(fp);
    return i;
}

void printList(char *list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == 0)
        {
            continue;
        }
        printf("%s\n", list[i]);
    }
}

void sortCharsInString(char *str)
{
    char temp;
    int n = strlen(str);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(str + i) < *(str + j))
            {
                continue;
            }
            //do swap
            temp = (char)*(str + j);
            *(str + j) = (char)*(str + i);
            *(str + i) = (char)temp;
        }
    }
}

int isUnScrambled(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    if (n1 != n2)
        return -1;

    char *c = malloc(sizeof(char) * n1), *d = malloc(sizeof(char) * n1);
    strcpy(c, a);
    strcpy(d, b);
    sortCharsInString(c);
    sortCharsInString(d);

    int r = strncmp(c, d, n1);

    free(c);
    free(d);
    return r;
}
