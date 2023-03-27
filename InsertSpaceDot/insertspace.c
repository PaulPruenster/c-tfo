#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* insertSpaceDot (char* bla)
{
	int len = strlen(bla) + 1;
	char temp[len];

	for (int i = 0; i < len; i++)
	{
		temp[i] = bla[i];
	}
	temp[len - 2] = ' ';
	temp[len - 1] = '.';
	temp[len] = '\0';

	for (int i = 0; i <= len; i ++) printf("%i: [%c][%i]\n", i, temp[i], temp[i]);

	return temp;	
}

int main ()
{
	char bla[99] = "This is fucking cancer.";  

	printf("Before(%i): [%s]\n", strlen(bla), bla);	

	char* test = *insertSpaceDot(bla);
	
	printf("After(%i): [%s]\n", strlen(test), test);	
	
	return 0;
}
