#include <stdio.h>
#include <string.h>
#include <math.h>

typedef char *string;

float count_words(string text);
float count_sentences(string text);
float count_letters(string text);

int main(void)
{
    string text;
    printf("Text: ");
    scanf("%[^\n]%*c", text);

    float words = count_words(text);
    float sentences = count_sentences(text);
    float letters = count_letters(text);

    float L = (letters / words) * 100.0;
    float S = (sentences / words) * 100.0;

    float grade = 0.0588 * L - 0.296 * S - 15.8;

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(grade));
    }
}

float count_words(string text)
{
    float words = 1.0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

float count_sentences(string text)
{
    float sentences = 0.0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

float count_letters(string text)
{
    float letters = 0.0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '!' && text[i] != '\'' && text[i] != '?')
        {
            letters++;
        }
    }

    return letters;
}