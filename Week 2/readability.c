#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main(void)
{
    string text = get_string("Text: ");
    int count_letter = 0, count_word = 1, count_sentence = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           count_letter++;
       }
       else if (text[i] == ' ')
       {
           count_word++;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
           count_sentence++;
       }
    }

    float L = (float) count_letter / (float) count_word;
    float S = (float) count_sentence / (float) count_word;
    float index = 0.0588 * (100 * L) - 0.296 * (100 * S) - 15.8;
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}