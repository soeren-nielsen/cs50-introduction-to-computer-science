#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: "); // Prompts user for input
    int letters, words, sentences; // Declares the variables words, sentences and letters
    letters = words = sentences = 0; // Sets the value of variables words, sentences and letters to 0
    for (int i = 0, length = strlen(s); i < length; i++) // Initialise for-loop over string s and uses the strlen function to calculate the length of the string which then is stored in the variable length
    {
        if (isalpha(s[i])) // Checks if i is an alphabetical character, if so it adds 1 to the variable letters
            letters++; // Increases the value of the variable letters with 1
        if ((i == 0 && s[i] != ' ') || (i != length - 1 && s[i] == ' ' && s[i + 1] != ' '))
            words++; // Increases the value of the variable words with 1
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
            sentences++; // Increases the value of the variable sentences with 1
        }
        float L = (letters / (float) words) * 100; // Declares the variable L as a float and sets it to letter divided by words multiplied by 100
        float S = (sentences / (float) words) * 100;
        int index = round(0.0588 * L - 0.296 * S - 15.8); // Coleman-Liau index algorithm from pset2
        if (index < 1)
            printf("Before Grade 1\n");
        else if (index >= 16)
            printf ("Grade 16+\n");
        else
            printf("Grade %i\n", index);
}