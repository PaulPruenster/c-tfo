#include <stdio.h>
#include <string.h>


/* ret = return array address */
void genCheck (char data[], char genKey[], char ret[])
{
	printf("\n[%s:%s]\n", data, genKey);
	
	

}

void checkSum (char data[], char genKey[], char sum[])
{
	// genCheck (data, genkey)
	// comp sum with sum
}

int main (int argc, char* argv[])
{
	if (argc == 3) // Berechnen checksum
	{
		char sum[strlen(argv[2])];
		char data[strlen(argv[1]) + strlen(argv[2])];
		char gen[strlen(argv[2])];
		
		// Nullen am ende hinzufügen
		for (int i = 0; i < (strlen(argv[1])+strlen(argv[2])-1); i++)
			data[i] = (i < strlen(argv[1])) ? argv[1][i] : '0';
		
		strcpy(gen , argv[2]);
		genCheck(data, gen, sum);
		
	} else if (argc == 4) // Überprüfen
	{
		printf("Überprüfe %s mit %s (genKey %s)\n", argv[1], argv[3], argv[2]);
		
	} else // Fehler
		printf("Usage: %s <data> <genkey> [<checksum>]\n", argv[0]);
	
	return 0;	
}
