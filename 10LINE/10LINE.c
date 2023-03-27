#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXIT 10000

int main (int argc, char *argv[])
{
	srand(time(NULL));
	if (argc == 2)
	{
		int per = atof(argv[1]);		
		double r;
		
		for (int i = 0; i < MAXIT; i++)
		{
			r = (float)rand()/(float)RAND_MAX;
			if (r > per)
				printf("/");
			else
				printf("\\");
		}
	}
	else
		printf("usage: %s <\%>\n", argv[0]);
}
