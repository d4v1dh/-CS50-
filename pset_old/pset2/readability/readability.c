#include <stdio.h>
#include <cs50.h>
#include <math.h>

int         main(void)
{
    int     letters = 0, words = 1, sentences = 0;
    int     i;

    string text = get_string("Text: ");
    //printf("%i,%i,%i\n", letters, words, sentences);

    i = 0;
    while (text[i] != '\0')
    {
        for (; (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ; i++)
        {
            letters++;
        }

        if (text[i] == ' ')
        {
            words++;
            i++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
            i++;
        }
        else
        {
            i++;
        }
    }

    float L = ((float)letters * 100 / words);
    float S = ((float)sentences * 100 / words);

    float index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}
