#include <stdio.h>
#include <math.h>
#include "polynommodul.h"

int main (void) 
{
	float min, max, miny, maxy, diff, diffy, toleranz; 	
	
	printf("\nNullstellen durch Intervallhalbierung\n");
	
	// Eingabe aller Werte
	printf("\nGeben Sie den Anfangspunkt des Intervalles ein: ");
	scanf(" %f", &min);

	printf("Geben Sie den Endpunkt des Intervalles ein: ");
        scanf(" %f", &max);
	
	// Berechnung des Punktes in der Mitte des Intervalles
	diff = (max - min)/2;	

	printf("Geben Sie die Toleranz ein: ");
        scanf(" %f", &toleranz);

	// Eingabe der Funktion
	polyinit();
	
	// Wenn die beiden Pukte des Intervalles beide positiv oder negativ sind gibt es keine Lösung und Schleife wird übersprungen
	miny = polymath(min);
	maxy = polymath(max);	
	// printf(" %f, %f\n", miny, maxy);

	if (((maxy >= 0) && (miny >= 0)) || ((maxy < 0) && (miny < 0)))
	{
		printf("Es gibt keine Nullstelle in diesem Intervall\n"); fflush(stdout);
		min = 0;
		max = 0;
		diff = 0;
	}

	while (max - min > toleranz) {
		// Mittleren Punkt berechnen
		diff = (max + min)/2;
		// y Koordinate jedes x-Punktes berechnen
		maxy = polymath(max);
		miny = polymath(min);
		diffy = polymath(diff);
		
		
		if (((miny > 0) && (diffy > 0)) || ((miny < 0) && (diffy < 0)))
			min = diff;
		else
		// if (((maxy > 0) && (diffy > 0)) || ((maxy < 0) && (diffy < 0)))
			max = diff;

	}
	
	// Es gibt eine Lösung	
	if (diff < 0 || diff > 0)
		printf("\nDie Nullstelle lautet %f\n", (max + min)/2);

	return 0;
} 
