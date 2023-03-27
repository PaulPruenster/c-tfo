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
		
		// Fügt nach jedem 9. Bit ein Paritätsbit ein das je nach 
		// gerader oder ungerader Anzahl Einsen 1 oder 0 ist
		char inhalt[MAX];
		
		fgets(inhalt, MAX, in);
		
		if (((strlen(inhalt) - 1) % 8) == 0)
		{
			int anzeins = 0;
			char bit;
			for (int i = 0; i < strlen(inhalt); i++)
			{
				bit = inhalt[i];
				
				// printf(" %c[%i] \n", bit, i);
				
				// Normales bit, wird gezählt und ausgegeben
				if (bit == '1')
					anzeins++;
				
				fputc(bit, out);
				
				// nach jedem byte wird je nach gerader oder ungerader Anzahl Einsen,
				// eine Null oder eine Eins ausgegeben
				if ((i + 1) % 8 == 0)
				{
					// printf(" | i: %i out: %i \n", i, anzeins % 2);
					if (anzeins % 2 == 1)
						fputc('1', out);
					else
						fputc('0', out);
						
					anzeins = 0;
				}
			}
			return 0;
		}
		else {
			int bits = strlen(inhalt) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("Bytes: %i, excssive bits: %i\n", (int)(bits / 8), bits % 8);
			
			return 3;
		}
		
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
		
		if (((strlen(inhalt) - 1) % 9) == 0)
		{
			char bit;
			for (int i = 0; i < strlen(inhalt); i++)
			{
				bit = inhalt[i];
				
				fputc(bit, out);
				
				if ((i + 1) % 8 == 0)
					i++;
			}
			return 0;
		}
		else {
			int bits = strlen(inhalt) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("Bytes with paritybit: %i, excssive bits: %i\n", (int)(bits / 9), bits % 9);
			
			return 3;
		}
		
		return 0;
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
		
		if (((strlen(inhalt) - 1) % 9) == 0)
		{
			char bit;
			int anzeins = 0;
			for (int i = 0; i < strlen(inhalt); i++)
			{
				bit = inhalt[i];
				
				if (bit == '1')
					anzeins++;
				
				if ((i + 1) % 9 != 0)
				{
					printf(" %c [%i]\n", bit, i + 1);
				}else
				{
					printf(" |- paritybit: %c expected %i\n", bit, anzeins % 2);
					
				}
			}
			return 0;
		}
		else {
			int bits = strlen(inhalt) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("Bytes with paritybit: %i, excssive bits: %i\n", (int)(bits / 9), bits % 9);
			
			return 3;
		}
		
		return 0;
	}
	
	
	
	// something else
	else
	{
		printf("Undefined or missing operator(s)\n\n");
		
		printf("Syntax: -c : parity -c <infile> <outfile>\n");
		printf("        -x : parity -x <infile> <outfile>\n");
		printf("        -t : parity -t <infile>\n");
		
		return 42;
	}
}
