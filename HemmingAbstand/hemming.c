#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 999

char xor(char a, char b)
{
	if ((a == '1' && b == '0') || (a == '0' && b == '1'))
		return '1';
	else
		return '0';
}



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
		
		// Encryptet jeden Byte nach Hemming
		char inh[MAX];
		
		fgets(inh, MAX, in);
		
		if (((strlen(inh) - 1) % 8) == 0)
		{
			for (int i = 0; i < strlen(inh) - 1; i += 8)
			{
				
				/*
				Hemming xor
				
				d0 d1 d2 d3 d4 d5 d6 d7
									
				p0 = d0 d1 d3 d4 d6		AB X
				p1 = d0 d2 d3 d5 d6		00 0
									01 1
				p2 = d1 d2 d3 d7		10 1
				p3 = d4 d5 d6 d7		11 0
				
				p0 p1 d0 p2 d1 d2 d3 p3 d4 d5 d6 d7
				*/
				
				printf("%i\n", i);
				
				fputc(xor(inh[i + 0], xor(inh[i + 1], xor(inh[i + 3], xor(inh[i + 4], inh[i + 6])))), out); // p0
				fputc(xor(inh[i + 0], xor(inh[i + 2], xor(inh[i + 3], xor(inh[i + 5], inh[i + 6])))), out); // p1
				
				fputc(inh[i + 0], out); // d0
				
				fputc(xor(inh[i + 1], xor(inh[i + 2], xor(inh[i + 3], inh[i + 7]))), out); // p2
				
				fputc(inh[i + 1], out); // d1
				fputc(inh[i + 2], out); // d2
				fputc(inh[i + 3], out); // d3
				
				fputc(xor(inh[i + 4], xor(inh[i + 5], xor(inh[i + 6], inh[i + 7]))), out); // p3
				
				fputc(inh[i + 4], out); // d4
				fputc(inh[i + 5], out); // d5
				fputc(inh[i + 6], out); // d6
				fputc(inh[i + 7], out); // d7
			}
			return 0;
		}
		else {
			int bits = strlen(inh) - 1;
			
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
		
		char inh[MAX];
		
		fgets(inh, MAX, in);
		
		if (((strlen(inh) - 1) % 11) == 0)
		{
			for (int i = 0; i < strlen(inh) - 1; i += 11)
			{
				// Encryption Paritybits mit Encrypteten Datenbits Paritybits Xoren für Fehlerstelle
				
				/*
				Hemming xor
				
				d0 d1 d2 d3 d4 d5 d6 d7
									
				p0 = d0 d1 d3 d4 d6		AB X
				p1 = d0 d2 d3 d5 d6		00 0
									01 1
				p2 = d1 d2 d3 d7		10 1
				p3 = d4 d5 d6 d7		11 0
				
				p0 p1 d0 p2 d1 d2 d3 p3 d4 d5 d6 d7
				*/
				
				
				// Paritybits of Input
				char inparity[4];
				inparity[0] = inh[i + 0]; // p0 1
				inparity[1] = inh[i + 1]; // p1 1
				inparity[2] = inh[i + 3]; // p2 1
				inparity[3] = inh[i + 7]; // p3 1
				
				
				// Partitybits of Databits
				char daparity[4];
				daparity[0] = xor(inh[i + 2], xor(inh[i + 4], xor(inh[i + 6], xor(inh[i + 8], inh[i + 10])))); // p0 2
				daparity[1] = xor(inh[i + 2], xor(inh[i + 5], xor(inh[i + 6], xor(inh[i + 9], inh[i + 10])))); // p1 2
				daparity[2] = xor(inh[i + 4], xor(inh[i + 5], xor(inh[i + 6], inh[i + 11]))); // p2 2
				daparity[3] = xor(inh[i + 8], xor(inh[i + 9], xor(inh[i + 10], inh[i + 11]))); // p3 2
				
				
				// Xor of Pariybits (fail?)
				int fehlerstelle = 0;
				for (int i = 0; i < 4; i++)
					fehlerstelle += xor(inparity[i], daparity[i]) * pow(2, i);


				// Byte to  char byte[]
				char byte[11];
				for (int n = 0; n < 11; n++)
					byte[n] = inh[i + n];
				
				
				// Korrektur und oder Ausgabe
				// p0 p1 d0 p2 d1 d2 d3 p3 d4 d5 d6 d7
				printf("Fehler: %i\n", fehlerstelle);
				
				// Korrektur
				if (fehlerstelle > 0)
					byte[fehlerstelle] = (byte[fehlerstelle] == 0 ? 1 : 0);
				
				// Ausgabe der DatenBits
				fputc(byte[ 2], out); // d0
				fputc(byte[ 4], out); // d1
				fputc(byte[ 5], out); // d2
				fputc(byte[ 6], out); // d3
				fputc(byte[ 8], out); // d4
				fputc(byte[ 9], out); // d5
				fputc(byte[10], out); // d6
				fputc(byte[11], out); // d7					
			}
			return 0;
		}
		else {
			int bits = strlen(inh) - 1;
			
			printf("excessive amount of bits (%i)\n", bits);
			printf("Hemmingbytes: %i, excssive bits: %i\n", (int)(bits / 11), bits % 11);
			
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
