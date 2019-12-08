#include <stdio.h>
#include <stdbool.h>

void anger(int nums[], int size)
{
    printf("No, I did guess but you lied!\n");
    printf("It was either\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\n", nums[i]);
    }
    printf("or\n");
    printf("%d\n", nums[size - 1]);
    printf("I don't want to play with you anymore\n");
}

//even average
int average2(int a, int b)
{
    int average = (a + b);
    if (average % 2 == 1)
        average++;
    return average / 2;
}

void game(bool *playGame)
{
    int num = 64, low = 0, high = 100;

    const int maxTries = 7;
    int tries = 0;

    int nums[] = {0, 0, 0, 0, 0, 0, 0};
    char c;

    while (c != 'y' && tries < maxTries)
    {
        printf("Number is %d\n", num);
        c = getchar();

        if (c != 'H' && c != 'h' && c != 'L' && c != 'l')
            continue;
        switch (c)
        {
        case 'H':
        case 'h':
            high = num; //move bound down
            break;
        case 'L':
        case 'l':
            low = num; //move bound up
            break;
        default:
            break;
        }
        num = average2(low, high);
        nums[tries] = num;
        tries++;
    }
    if (c == 'y')
    {
        printf("Hoorah, I won!\n");
    }
    else if (tries == maxTries)
    {
        //machine should have guessed in 7 tries
        //machine expresses its anger over faulty human nature
        anger(nums, maxTries);
        *playGame = false;
    }
}
void preGame(bool *playGame)
{
    //explainKeys();
    printf("wish the number between 1 and 100\n");
    printf("I'll try to guess\n");
    printf("Type y if I guessed\n");
    printf("L or l if value is lower than your number\n");
    printf("H if h value is higher than your number\n");
    printf("S or s to start game");
    char c;
    bool startGame = false;
    while (!startGame)
    {
        printf("Start game?\n");
        c = getchar();
        if (c == 's')
        {
            break;
        }
    }
    game(playGame);
}

int main()
{
    char c;
    bool playGame = true;
    while (c != 'x' && playGame)
    {
        printf("Wanna play game?\n");
        printf("type y for yes.\n");
        printf("type x for exit.\n");
        c = getchar();
        if (c == 'x')
            continue;
        if (c == '\n')
            continue;
        preGame(&playGame);
    }
    printf("Maybe, tommorow ?\n");

    return 0;
}