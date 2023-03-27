#include <stdio.h>
#include <string.h>

void setboard(char feld[]);
void printBoard(char feld[]);
// int isOcupied (int col, int row);
// int isWin (void);


int main (void)
{
printf("  ,--------.,--.      ,--------.             ,--------.        	     \n");
printf("  '--.  .--'`--' ,---.'--.  .--',--,--. ,---.'--.  .--',---.  ,---.  \n");
printf("     |  |   ,--.| .--'   |  |  ' ,-.  || .--'   |  |  | .-. || .-. : \n");
printf("     |  |   |  |\\ `--.   |  |  \\ '-'  |\\ `--.   |  |  ' '-' '\\   --. \n");
printf("     `--'   `--' `---'   `--'   `--`--' `---'   `--'   `---'  `----' \n\n");
	
	char feld[9];
	int eingabe;
	
	setBoard(feld);
	
	printBoard(feld);

}

void setBoard(char feld[])
{
	for (int i = 0; i < 9; i++)
		feld[i] = ' ';
}

void printBoard(char feld[])
{
		printf(" %c | %c | %c \n", feld[0], feld[1], feld[2]);
		printf("-----------\n");
		printf(" %c | %c | %c \n", feld[3], feld[4], feld[5]);
		printf("-----------\n");
		printf(" %c | %c | %c \n", feld[6], feld[7], feld[8]);
}
