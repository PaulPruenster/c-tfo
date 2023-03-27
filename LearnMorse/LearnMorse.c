#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int randI(int high)
{
     return rand() % high;
}

int main ()
{
	char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	char* chars[] = {"A" ,"B"   ,"C"   ,"D"  ,"E","F"   ,"G"  ,"H"   ,"I" ,"J"   ,"K"  ,"L"   ,"M" ,"N" ,"O"  ,"P"   ,"Q"   ,"R"  ,"S"  ,"T","U"  ,"V"   ,"W"  ,"X"   ,"Y"   ,"Z"   };
	
	printf("LEARN MORSE!\nenter q to quit\nenter '.' for short, '-' for long\nexample: A= \".-\"\n\n");
	srand(time(NULL));	
	
	// Main loop
	int akt;
	char* answer[10];
	while (1)
	{
		akt = randI(26);
		printf("\n:%s\n>", chars[akt]);
		scanf(" %s", answer);
		
		// Check input for "q"
		if (!strcmp(answer, "q"))
			exit(0);
		
		// Check input
		if (strcmp(answer, morse[akt]))
		{
			// False
			printf("Wrong: %s = %s\n", chars[akt], morse[akt]);
		}
		else
		{
			// True
			printf("CORRECT!\n");
		}
	}
		
	
	return 0;
}
