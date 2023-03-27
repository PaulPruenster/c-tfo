#include <stdio.h>

int main(void)
{
	float zahl1 = 0;
	float zahl2 = 0;
	char op = '+';
	float summe = 0;
	
	printf("	##Einfacher Rechner##	\n");
	printf("\nGeben Sie die erste Zahl ein: ");
	scanf(" %f", &zahl1);
	
	printf("Geben Sie die '+', '-', '*' oder '/' ein: ");
        scanf(" %c", &op);
	
	printf("Geben Sie die zweite Zahl ein: ");
        scanf(" %f", &zahl2);
	
	/*printf(" %c, %i, %i", op, zahl1, zahl2); */
	
	if (op == '+')
	{
		summe = zahl1 + zahl2;
	}
	else
	if (op == '-')
	{
		summe = zahl1 - zahl2;
	}
	else
	if (op == '*')
	{
		summe = zahl1 * zahl2;
	}
	else
	if (op == '/')
	{
		summe = zahl1 / zahl2;
	}
	else
		printf("Geben Sie '+', '-', '*', oder '/' ein\n");
	if (op == '+' || op == '-' || op == '*' || op == '/')
	{
		printf("\nDas Ergebnis ist %f\n", summe);
	}
	return 0;	
}
