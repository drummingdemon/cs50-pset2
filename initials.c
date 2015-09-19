/*
 *  initials.c
 *
 *  Harvard CS50x3 - Problem Set 2 - Initials
 *
 *  Prompts the user for their name and outputs their initials in uppercase
 *
 *  Gábor Hargitai <gabriel.hargitai@gmail.com>
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Capitalizes the selected character at the given index
// by analyzing its' ASCII value
void capitalize(char character[], int index)
{
    if (character[index] >= 65 && character[index] <= 90)
    {
        printf("%c", character[index]);
    }
    else
    {
        printf("%c", (character[index]-32));
    }
}

// The first character in the given name is automatically
// capitalized, after that it searches for a separating space
// character. Upon finding it, the next character after the
// space is capitalized.
int main(int argc, char *argv[])
{  
    string s = GetString();
    
    capitalize(s, 0);
       
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            capitalize(s, i+1);
        }
    }
    
    printf("\n");
    
    return 0;
}
