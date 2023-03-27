#include <stdio.h>
#include <string.h>

#define CORES 4
#define MAXIT 10000

// Returns amount of points in a quarter circle od radius 1
int picalc()
{
	double x, y;
	
	int inside = 0;
	for (int i = 0; i < MAXIT; i++)
	{
		x = (double)rand()/MAX_RAND;
		y = (double)rand()/MAX_RAND;
		
		if ((x * x) + (y * y) < 1)
			inside++;
	}
}

int main (void)
{	
	int[CORES][2];
	
	for (int i = 0; i < CORES; i++)
	{
		int pid = fork();
		if (pid == 0)
			i = CORES;
	}
	
	
}
