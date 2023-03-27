#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

// TODO better color(s)
// \e[92m green
// \e[39m normal

char* spaceDot(char* string)
{	
	// insetrt space at lengh - 2
	return string;
}

char* substring(char* str, int begin, int len)
{
  	if (str == 0 || strlen(str) == 0)
		return str;
		
  	return strndup(str + begin, len);
}

char* removeComments (char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		// if comment, remove everything to the right and return string
		if (string[i] == '#')
		{
			string = substring(string, 0, i);
			i = len;
		}
		//printf("%s[%i]: (%c)\n", string, i, string[i]);
	}
	
	return string;
}

char* removeDoubleSpace (char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		// if there are 2 spaces or a tab, remove char
		if ((string[i] == ' ' && string[i + 1] == ' ') || string[i] == '\t')
		{
			memmove(&string[i], &string[i + 1], strlen(string) - i);
			i--;
		}
	}
	
	// If there is a space at the start of the string, remove it
	if (string[0] == ' ')
		memmove(&string[0], &string[1], strlen(string));
		
	// If there is a space at the end of the string, remove it
	int len = strlen(string);
	if (string[strlen(string) - 1] == ' ')
		memmove(&string[len - 1], &string[len], 1);
	
	return string;
}

int main(int argc, char *argv[])
{
    	printf("NUKI C COMPILER\n(args: %i)\n\n", argc - 1);
	
    	// Check inputfile
    	if (argc == 1)
    	    printf("No inputfile passed\n");
	
    	// Check file extention (0 = false, 1 = true)
    	if (argc == 2)
    	{
    	int fail = 0;
    	    int len = strlen(argv[1]);
    	    
    	    // Test ".nc" at the end of string
    	    fail = (argv[1][len - 3] == '.') ? 0 : 1;
    	    fail = (argv[1][len - 2] == 'n') ? 0 : 1;
    	    fail = (argv[1][len - 1] == 'c') ? 0 : 1;
    	
    	    if (fail) {
    	    	    printf("File format not recognized: not NukiC ( .nc )\n");
    	    	    exit(1);
    	    }
    	}
    
    	// Check for to many args
    	if (argc != 2)
    	{
    	    	printf("Wrong argument usage\nUsage: <file>\n");
    	   	exit(1);
    	}
    
	// ############ TESTS COMPLETE ############
	
    	printf("Compiling: %s\n", argv[1]);

    	// import code into string and format it
    	FILE *in = fopen(argv[1], "r");
    	if (in == NULL)
    	{
    		printf("Infile failed. Exit");	
    		exit(1);
    	}
    	
    	printf("\nIMPORTING\n");
    	
    	// Get lines in file
    	int lines = 0;
    	char ch;
    	while(!feof(in))
    	{
    		ch = fgetc(in);
		if(ch == '\n')
     	{
     		lines++;
     	}
    	}	
    	printf("lines in file: \e[92m%i\e[39m\n\n", lines);
    	
    	// Reset the filepointer
    	fseek(in, 0, SEEK_SET);
    	
    	// Charpointer array with every line in the file
    	char *rawcode[lines];
    	char buffer[999];

	// && fgets(buffer, sizeof(buffer), in) != 0
    	for (int i = 0; i < lines; i++)
    	{
    		fgets(buffer, sizeof(buffer), in);
     	buffer[strcspn(buffer, "\n")] = '\0';
     	rawcode[i] = strdup(buffer);
    	}
	// Close filepointer
    	fclose(in);
   	
   	for (int i = 0; i < lines; i++)
        	printf("[\e[92m%s\e[39m]\n", rawcode[i]);
   	
   	printf("\nIMPORT SUCCESSFUL!\n");
   	
   	
   	// Start processing data
    	printf("\nPROCESSING DATA!\n");
    	
    	int usable = 0;
    	for (int i = 0; i < lines; i ++)
    	{
    		rawcode[i] = removeComments(rawcode[i]); // Remove comments from strings
		rawcode[i] = removeDoubleSpace(rawcode[i]); // Remove double, spaces, tabs etc
		rawcode[i] = spaceDot(rawcode[i]); // insert a space before the . at the end
		
		if (strlen(rawcode[i]) > 0) 
			usable++;
    	}
    	
    	// copy usable lines in a new array (not the empty lines)
    	printf("usable lines: \e[92m%i\e[39m\n\n", usable);
    	char* code[usable];
    	for (int i = 0, j = 0; i < lines; i++)
    	{
    		if (strlen(rawcode[i]) > 0)
    		{
    			code[j] = rawcode[i];
    			j++;
    		}
    	}
    	
    	// TODO
    	// intert space before dots
    	// free rawcode array?
    	
    	
    	
    	for (int i = 0; i < usable; i++)
        	printf("[\e[92m%s\e[39m]\n", code[i]);
        	
        	
	// Start identification: see if line is a operand ({,}), function or statement
    	return 0;
}













