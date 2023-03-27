#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *dB(int dez, int len)
{
	char bin[len];
	
	for (len-- ; len >= 0; len--)
	{
		if (dez % 2 == 0)
		{
			bin[len] = '0';
			dez /= 2;
		} else
		{
			dez = (dez - 1) / 2;
			bin[len] = '1';
		}
	}
	
	char *ret = bin; // Scheiß pointer
	return ret;
}

int main (int argc, char* argv[])
{
	// Tutorial
	if (argc == 1)
	{
		printf("Usage: %s <word1> <word2> ...\n", argv[0]);
		exit(-1);
	}

	// Start	
	int words = argc -1;
	int cases = pow(2, words);
	printf("Words: %i Cases: %i\n\n", words, cases);
	
	cases--; // Start bei cases -1 weil 0
	
	for ( ; cases >= 0; cases--)
	{
		char *bin = dB(cases, words);
		
		printf("%i [", cases);
	 	for (int i = 0; i < words; i++)
	 	{
	 		if (bin[i] == '1')
	 			printf("%s", argv[i + 1]);
	 	}
	 	printf("]\n");
	}

	return 0;
}
