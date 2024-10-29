#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calcIndex(string s);

int main(int argc, string argv[])
{
    string someText = get_string("Text: ");

    if (strlen(someText) != 0)
    {
        int index = calcIndex(someText);

        if (index > 1)
        {
            if (index >= 16)
            {
                printf("Grade 16+\n");
            }
            else if (index < 16)
            {
                printf("Grade %i\n", index);
            }
        }
        else
        {
            printf("Before Grade 1\n");
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

int calcIndex(string s)
{
    float index = 0;
    int lettersCounter = 0;
    int sentenceCounter = 0;
    int wordsCounter = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            lettersCounter++;
        }
        else if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            sentenceCounter++;
        }
        else if (s[i] == ' ')
        {
            wordsCounter++;
        }
        else
        {
            continue;
        }
    }

    float averageLetters = ((float) lettersCounter / (float) wordsCounter) * 100.0;
    float averageSentences = ((float) sentenceCounter / (float) wordsCounter) * 100.0;

    index = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);
    return (int) index;
}
