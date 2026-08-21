#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int letter_count(string text);
int word_count(string text);
int sentences_count(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = letter_count(text);
    int words = word_count(text);
    int senten = sentences_count(text);
    //printf("%i\n", letters);
    //printf("%i\n", words);
    //printf("%i\n", senten);
    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    // Where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float index = 0.0588 * (((float) letters/words)*100.0) - 0.296 * (((float) senten/words)*100.0) - 15.8;
    // Print the grade level
    if (index < 1)
    {    
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n", (int)round(index));
}

int letter_count(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
            sum += 1;
    }
    return sum;
}
int word_count(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text) + 1; i++)
    {
        if (text[i] == ' ')
            sum += 1;
        else if (text[i] == '\0')
            sum += 1;
    }
    return sum;
}
int sentences_count(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text) + 1; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sum += 1;
    }
    return sum;
}
