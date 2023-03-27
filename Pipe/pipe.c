#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// Wenn falsch aufgerufen
	if (argc != 2)
	{
		printf("Try: %s <message>\n", argv[0]);
		exit(-1);
	}

	// Pipe erstellen
	int p[2];
	int piperet = pipe(p);
	if (piperet < 0)
	{
		printf("Pipe failed");
		exit(-1);
	}
	
	// Prozess teilen
   	int pid = fork();
	if (pid < 0)
	{
		printf("Exit");
		exit(-1);
	}
	
	// Child
	if (pid == 0)
	{
		char buf;
		
		sleep(1);
		
		printf("Child pid: %i\n", pid);
		
		while (read(p[0], &buf, 1) > 0)
                   printf("a %c", buf);

          printf("\n");
          close(p[0]);
          exit(0);
	}
	
	// Parent
	printf("Parent pid: %i\n", pid);
	close(p[0]);
	write(p[1], argv[1], strlen(argv[1]));
}

