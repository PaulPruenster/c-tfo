#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int o = atoi(argv[1]) - 1;
		for( ; o > 0; o--)
			printf("O");
	}
	printf("OLEX!\n");
}
