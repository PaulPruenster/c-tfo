#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

int main (int argc, char *argv[])
{
	
	if (argc == 1)
	{
		printf("try -c, -x or -t\n");
		return 3;
	}
	
	
	// -c
	else if (*(argv[1] + 1) == 'c' && argc == 4)
	{
		printf("-c\n");
		
		FILE *in  = fopen(argv[2], "r");
		FILE *out = fopen(argv[3], "w");
		
		if (in == NULL)
		{
			printf("Infile failed\n");
			return 1;
		}
			
		if (out == NULL)
		{
			printf("Outfile failed\n");
			return 2;
		}
		
		// aus 1 mach 3
		char inhalt[MAX];
		fgets(inhalt, MAX, in);
		

		char bit;
		for (int i = 0; i < strlen(inhalt); i++)
		{
			bit = inhalt[i];
			
			for (int i = 0; i < 3; i++) fputc(bit, out);
		}
		return 0;
	}
	
	
	// -x
	else if (*(argv[1] + 1) == 'x' && argc == 4)
	{
		printf("-x\n");
		
		FILE* in  = fopen(argv[2], "r");
		FILE* out = fopen(argv[3], "w");
		
		if (in == NULL)
		{
			printf("Infile failed\n");
			return 1;
		}
			
		if (out == NULL)
		{
			printf("Outfile failed\n");
			return 2;
		}
		
		char inhalt[MAX];
		fgets(inhalt, MAX, in);
		
		if (((strlen(inhalt) - 1) % 3) == 0)
		{
			char bit;
			for (int i = 0; i < strlen(inhalt) - 1; i+=3)
			{
				int anzeins = 0;
				for(int j = 0; j < 3; j++)
				{
					bit = inhalt[i+j];
					
					if (bit == '1')
						anzeins++;
				}
				
				fputc(anzeins >= 2 ? '1' : '0', out);				
			}
			return 0;
		}
		else {
			int bits = strlen(inhalt) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("3-bit-gruppen: %i, excessive bits: %i\n", (int)(bits / 3), bits % 3);
			
			return 3;
		}
	}
	
	
	// -t
	else if (*(argv[1] + 1) == 't' && argc == 3)
	{
		printf("-t\n");
		
		FILE* in  = fopen(argv[2], "r");
		
		if (in == NULL)
		{
			printf("Infile failed\n");
			return 1;
		}
		
		char inhalt[MAX];
		fgets(inhalt, MAX, in);
		
		if (((strlen(inhalt) - 1) % 3) == 0)
		{
			char bit;
			for (int i = 0; i < strlen(inhalt) - 1; i+=3)
			{
				int anzeins = 0;
				for(int j = 0; j < 3; j++)
				{
					bit = inhalt[i+j];
					
					printf("%c ", bit);
					
					if (bit == '1')
						anzeins++;
				}
				
				// 2aus3 Bit				
				printf(" anz1: %i, 2aus3-bit: %c \n", anzeins, anzeins >= 2 ? '1' : '0');
			}			
			return 0;
		}
		else {
			int bits = strlen(inhalt) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("3-bit-gruppen: %i, excessive bits: %i\n", (int)(bits / 3), bits % 3);
			
			return 3;
		}
	}
	
	
	
	// something else
	else
	{
		printf("Undefined or missing operator(s)\n\n");
		
		printf("Syntax: -c : 2aus3 -c <infile> <outfile>\n");
		printf("        -x : 2aus3 -x <infile> <outfile>\n");
		printf("        -t : 2aus3 -t <infile>\n");
		
		return 42;
	}
}
