#include <stdio.h>
#include <math.h>

int main (void)
{
	printf("Simsons Integral\n\n");
	
	double dt, anfang, end, summe;
	printf("Genauigkeit: ");
	scanf(" %lf", &dt);
	
	printf("Anfang: ");
	scanf(" %lf", &anfang);
	
	printf("Ende: ");
	scanf(" %lf", &end);
	
	for (double t = anfang; t < end; t += dt)
		summe += dt / 6 * (pow(t, 2) + 4 * (pow(t, 2) + pow(dt, 2) / 4) + pow(t, 2) + pow(dt, 2));
		
	printf("\nSumme: %lf \n", summe);
}
