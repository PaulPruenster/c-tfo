#include <stdio.h>
#include <stdlib.h>

/*
 *  Koefizienten:
 *  4   1  -1 = 3
 *  0   3   2 = 8
 *  2  -1   5 = 4
 *
 *  Ergebnis:
 *  0.5 2   1
 */
int main(void)
{
	int anzun;
	printf("Anzahl Unbekannte: ");
	scanf(" %i", &anzun);
	
	int rounds;
	printf("Anzahl Durchläufe: ");
	scanf(" %i", &rounds);
	
	
	// a1 b1 c1 = konst
	// a2 b2 c2 = konst
	// a3 b3 c3 = konst
	float koef[anzun][anzun + 1];
	
	// x1 x2 x3
	float vars[anzun];
	// Stellen auf 0 setzen
	for (int i = 0; i < anzun; i++)
		vars[i] = 0;		
	
	// Eingabe der Gleichungen
	for (int glg = 0; glg < anzun; glg++)
	{
		printf("Gleichung %i:\n", glg + 1);
		for (int kof = 0; kof < anzun; kof++)
		{
			printf("  x%i * ", kof + 1);
			scanf(" %f", &koef[glg][kof]);
		}
		printf("  = \n");
		printf(" Konst:");
		scanf(" %f", &koef[glg][anzun]);
	}
	
		
	// xn = (1 / ann) * (bn - (an1 x1 + ... + ann xn))
	for (int round = 0; round < rounds; round++)
	{
		// Für jede Glg
		for (int glg = 0; glg < anzun; glg++){
		
			// Summe der koef mit wars außer dem aktuellen
			float summe = 0;
			for (int n = 0; n < anzun; n++)
				if (n != glg)
					summe += koef[glg][n] * vars[n];
				
					
			// vars an der stelle ist ergebnis der formel
			vars[glg] = ((1 / koef[glg][glg]) * (koef[glg][anzun] - summe));
		}
		
		
	}
	
	// Ausgabe
	printf("\nArray: \n");
	for (int i = 0; i < anzun; i++) {
		for (int j = 0; j < anzun + 1; j++) {
			printf(" %f", koef[i][j]);
		}	
		printf("\n");
	}
	printf("Unbekannte: \n");
	for (int i = 0; i < anzun; i++)
		printf(" %f", vars[i]);
	
	printf("\n");
}
