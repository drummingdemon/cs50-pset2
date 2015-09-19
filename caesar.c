/*
 *  caesar.c
 *
 *  Harvard CS50x3 - Problem Set 2 - Hail, Caesar!
 *
 *  Encodes a given string with ROT cipher at a level given
 *  as a command line argument.
 *
 *  Gábor Hargitai <gabriel.hargitai@gmail.com>
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


void spin(char chr[], int index)
{
    // case of ciphering a letter between A-Z
    if (chr[0] >= 65 && chr[0] <= 90)
    {
        int rotate = fmod(index, 26);
        
        if (rotate + chr[0] > 90)
        {
            chr[0] = 64 + fmod((chr[0] + rotate), 90);
            printf("%c", chr[0]);
        }
        else
        {
            printf("%c", chr[0]+rotate);
        }
    }
    // case of ciphering a letter between A-Z
    else if (chr[0] >= 97 && chr[0] <= 122)
    {
        int rotate = fmod(index, 26);
        
        if (rotate + chr[0] > 122)
        {
            chr[0] = 96 + fmod((chr[0] + rotate), 122);
            printf("%c", chr[0]);
        }
        else
        {
            printf("%c", chr[0]+rotate);
        }
    }
    // not a-z or A-Z, nothing to do with it
    else
    {
        printf("%c", chr[0]);
    }
}

int main(int argc, char *argv[])
{   
    // if no permutation number is given, we abort
    // and show this helpful usage text
    if (argc == 1)
    {
        printf("Usage: caesar [permutation_number]\n");
        return 1;
    }
    else 
    {
        string s = GetString();
                  
        for (int i = 0; i < strlen(s); i++)
        {
            spin(&s[i], atoi(argv[1]));
        }
        
        printf("\n");
        
        return 0;
    }
}
