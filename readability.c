#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // words starts at 1 in order to count
    // the first word that has't any space before.

    int letters = 0;
    int words = 1;
    int sentence = 0;

    string user_input = get_string("Text: ");

    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        // Detecting letters
        if (isalpha(user_input[i]))
        {
            letters++;

        }

        // Detecting words
        if (user_input[i] == ' ' && isalpha(user_input[i + 1]))
        {
            words++;
        }

        // Detecting sentece
        if (user_input[i] == '!' || user_input[i] == '?' || user_input[i] == '.' || user_input[i] == ':')
        {
            sentence++;
        }
    }

    float l = (float) letters / (float) words * 100;
    float s = (float) sentence / (float) words * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}