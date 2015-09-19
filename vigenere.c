/*
 *  vigenere.c
 *
 *  Harvard CS50x3 - Problem Set 2 - Vigenere
 *
 *  Encodes a given string with ROT cipher at a level indicated
 *  by the command line argument string, on a per char basis.
 *
 *  Gábor Hargitai <gabriel.hargitai@gmail.com>
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void spin(char chr[], int index)
{
    // converting uppercase keyword char to lowercase
    if (index >= 65 && index <= 90)
    {
        index = index + 32;
    }

	// case of ciphering a letter between A-Z
	if (chr[0] >= 65 && chr[0] <= 90)
	{
		// converting to lowercase
		chr[0] = chr[0] + 32;
		
		// sanitizing to preferred 0-25 range				
		int rotate = fmod((index - 97), 26);
		
		// avoiding overrun and converting back to uppercase
		if (rotate + chr[0] > 122)
		{
			chr[0] = 96 + fmod((chr[0] + rotate), 122);
			printf("%c", chr[0]-32);
		}
		else
		{
			printf("%c", chr[0]+rotate-32);
		}
	}
	
	// case of ciphering a letter between
	else if (chr[0] >= 97 && chr[0] <= 122)
	{	
		// sanitizing to preferred 0-25 range				
		int rotate = fmod((index - 97), 26);
		
		// avoiding overrun and converting back to uppercase
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
    // if no keyword is given or more than one is given
    // then we terminate and display this helpful text
	if (argc == 1 || argc > 2)
	{
		printf("Usage: vigenere [keyword]\n");
		
		return 1;
	}
	else 
	{
	    string keyword = argv[1];
	
    	int keywordLength = strlen(keyword);
	    
	    // Vigenere only works with alphabetic characters
	    // so we terminate if anything else is given as a keyword
	    for (int i = 0; i < keywordLength; i++)
	    {
	        if (!isalpha(keyword[i]))
	        {	        
	            printf("Please, use only letters between a-z and A-Z\n");
	            printf("Usage: vigenere [keyword]\n");
	            return 1;
	        }     	    
	    }
	
		string s = GetString();
		
		int j = 0;
				  
		for (int i = 0; i < strlen(s); i++)
		{			
			if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
			{			
				if (fmod(j, keywordLength) != 0)
				{ 
					spin(&s[i], argv[1][j]);
					j++;
				}
				else
				{
					j = 0;
					spin(&s[i], argv[1][j]);
					j++;
				}
			}
			else
			{
				printf("%c", s[i]);
			}			
		}
		
		printf("\n");
		
		return 0;
	}
}
