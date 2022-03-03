
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// After converting to ASCII, words are separated by spaces
// if we find how many spaces are, we get how many words we have.
int countwords(int n, int len, int i, float cntwords)
{
    if (n == 32)
    {
        cntwords++;
    }
    return cntwords++;
}

// After converting to ASCII, check in the range of letters.
int countchar(int n, int len, int i, float cntchar)
{
    if (64 < n && n < 91)
    {
        cntchar++;
    }
    else if (96 < n && n < 123)
    {
        cntchar++;
    }
    return cntchar;
}

// After converting to ASCII, check for exclamations, question marks
// and dots.
int countphrase(int n, int len, int i, float cntphrase)
{
    switch (n)
    {
        case 63:
            cntphrase++;
            break;
        case 33:
            cntphrase++;
            break;
        case 46:
            cntphrase++;
            break;
    }
    return cntphrase;
}


int main()
{
    string s = get_string("Text: ");

    int len = strlen(s);
    float cntphrase = 0;
    float cntwords = 0;
    float cntchar = 0;

    for (int i = 0; i < len; i++)
    {
        // Convert char to ASCII so it's easier to analyze.
        int n = s[i];
        cntwords = countwords(n, len, i, cntwords);
        cntphrase = countphrase(n, len, i, cntphrase);
        cntchar = countchar(n, len, i, cntchar);
    }
    cntwords++; // This is where we add the last word.

    float L = (cntchar / cntwords) * 100;
    float S = (cntphrase / cntwords) * 100;
    int in = round(0.0588 * L - 0.296 * S - 15.8);

    // More comments? How many more comments do you want?
    // I am adding the necessary comments but I ain't putting
    // comments where the action is evident.
    if (in >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (in < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", in);
    }
}


