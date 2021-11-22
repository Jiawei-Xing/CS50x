#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //prompt text
    string text = get_string("Text: ");
    
    //count letters, words, and sentences
    int l = 0;
    int w = 0;
    int s = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            l++;
        }
        else if (text[i] == ' ')
        {
            w++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
    }
    w += 1;
    
    //calculate reading level
    float L = ((float) l / w) * 100;
    float S = ((float) s / w) * 100;
    float r = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(r);
    
    //print out grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}