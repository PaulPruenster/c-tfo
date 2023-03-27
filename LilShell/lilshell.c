#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 99

// TODO: (make startclear nicer? :/ )

int main (void)
{

	// ### FIRST CLEAR ###
	int clear = fork();
	if (clear == 0)
	{
		char *cl[2];
		char clarr[6] = {'c', 'l', 'e', 'a', 'r', '\0'};
		
		cl[0] = &clarr[0];
		cl[1] = &clarr[5];

		execvp(cl[0], cl);
		exit(0);
	}
	
	wait(0);
	
	
	// ### SCREEN ###

	printf("\n\033[33;1m	 __    _ __    _____ _____ _____ __    __    \n");
	  printf("	|  |  |_|  |  |   __|  |  |   __|  |  |  |   \n");
	  printf("	|  |__| |  |__|__   |     |   __|  |__|  |__ \n");
	  printf("	|_____|_|_____|_____|__|__|_____|_____|_____|\n");
	  printf("	                                             \x1b[0m\n\n");	
	
		
	do
	{
		
		// ### BEFEHLSZEILE ###
		printf("\033[32;1m nuki@lilshell $: \x1b[0m");
		
		
		// ### EXIT ###
		char eingabe[MAX];
		fgets(eingabe, MAX, stdin);
		
		// Exit
		int jo = 1;
		char exitstring[4] = {'e', 'x', 'i', 't'};
		if (strlen(eingabe) == 5) // 4 + \n
		{
			jo = 0;
			for (int i = 0; jo == 0 && i < 4; i++)
				if (eingabe[i] != exitstring[i])
					jo = 1;
		}		
		if (jo == 0)
			exit(0);


		// ### SPLIT STUFF ###		
		
		// Eingabe in programm un argumente unterteilen;
		// Ersetzt jedes Leerzeichen mit einem '\0' und setzt einen 
		// charpointer auf die nächste stelle. Wenn der char ein '\n' ist
		// Wird auch dieses durch ein null ersetzt aber kein pointer auf die
		// nächste stelle gesetzt.
		int stelle = 0;
		int len = strlen(eingabe);
		
		char ausgabe[len];
		
		char *argv[100]; 
		
		// Programm
		argv[stelle] = &ausgabe[0];
		stelle++;		
		for (int i = 0; i <= len; i++)
		{
			// normaler char
			if (eingabe[i] != ' ' && eingabe[i] != '\n')
			{
				ausgabe[i] = eingabe[i];
			}
			// argument
			else if (eingabe[i] == ' ')
			{
				ausgabe[i] = '\0';
				argv[stelle] = &ausgabe[i + 1];
				stelle++;
			}
			// null
			if (eingabe[i] == '\n')
			{
				ausgabe[i] = '\0';
				argv[stelle] = '\0';
			}
		}
		
		
		// ### DEBUG ###
		
		//printf("len: %i;", len);
		//for (int i = 0; i <= stelle + 1; i++) printf("\"%s\"", argv[i]);
		
		
		// ### FORK ###
		int pid = fork();
		if (pid < 0)
		{
			printf("Mission Failed! Exiting lilshell"); fflush(stdout);
			exit(-1);
		}
		// Child
		if (pid == 0)
		{
			execvp(argv[0], argv);
			exit(0);
		}
		// Sicher Parent, warten auf child
		wait(0);

	} while(1);
}

