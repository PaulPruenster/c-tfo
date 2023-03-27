#include <stdio.h>
#include <string.h>

#define MAX 999


void help() {
	printf(" Commands:\n");
	printf(" help, print, new, set, color, q\n\n");

	printf("  help  - shows this\n");
	printf("  print - output the current calender\n");
	printf("  new   - make new calender\n");
	printf("  set   - set the value of a cell\n");
	printf("  color - color a cell\n");
	printf("  q     - quits the program\n");
}

int main() {

	printf("Calender Editor\n\n");
	printf("Type \"help\" to get started\n");

	char in[MAX];
	while (1) {
		printf(">>"); // TODO make help

		fgets(in, MAX, stdin); // input
		if (strcmp(in, "q\n") == 0)
			return 0;

		char * words[MAX]; // split input into tokens
    char * p;
		int wordcount = 0;
    p = strtok (in," ,.-\n");
    for ( ; p != NULL; wordcount++)
    {
			words[wordcount] = p;
      p = strtok (NULL, " ,.-\n");
    }

		printf("%i\n", wordcount);
		for (int	 i = 0; i < wordcount; i++) printf("[%s]\n", words[i]);

		if (strcmp(words[0], "help") == 0 && wordcount == 1)
			help();


	}
	return 0;
}
