#include <stdio.h>
#include <math.h>

// Variable und Array können in beiden Funktionen benutzt werden
static int anz = 0;
static float koef[1000];


int polyinit (void) 
{
	// Eingabe der Koefizienten
	printf("\nGeben Sie den höchsten Grad ein: ");	
	scanf(" %i", &anz );
	anz++;
	for (int i = 0; i < anz; i++)
	{
		printf("Geben sie den Koefizienten von x^%i ein: ", i);
		scanf(" %f", &koef[i]);
	}
	return 0;
}
	
float polymath (float x)
{	
	float pw = 0;
	// Funktion rechnet pw mit x und den koefizienten des Arrays aus
	for (int i = 0; i < anz; i++)
	{
		pw = pw + (koef[i - 1] * powf(x, i));
	}
	return pw;
}
