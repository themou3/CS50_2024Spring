#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeScore(string s);

int main(int argc, string argv[])
{

    string answer1 = get_string("Player 1: ");
    string answer2 = get_string("Player 2: ");

    int firstPlayerScore = computeScore(answer1);
    int secondPlayerScore = computeScore(answer2);

    if (firstPlayerScore > secondPlayerScore)
    {
        printf("Player 1 wins!");
    }
    else if (firstPlayerScore < secondPlayerScore)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("You tied\n");
    }
}

int computeScore(string s)
{
    int result = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            result += POINTS[s[i] - 'a'];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            result += POINTS[s[i] - 'A'];
        }
        else
        {
            break;
        }
    }
    return result;
}
