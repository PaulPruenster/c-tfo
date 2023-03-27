#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Sort array preis-leistung
// Alles einpacken bis nächstes nicht mehr platz hat, skipen und nächstes probieren
// Wenn ende von array erreicht, optimale lößung


// Switch pointers
void swap(char** a, char** b)
{
	char* temp = *b;
	*b = *a;
	*a = temp;
}

int main (int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Usage: %s <Item1> <Item2> <Item3> ...\n", argv[0]);
		return 0;
	}

	// Input weigth value
	int n = argc - 1;
	int values[n];
	int weigth[n];
	
	int max_weigth;
	printf("Max. weigth: ");
	scanf(" %i", &max_weigth);
	
	printf("\nInput weigth and value of the %i items:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("\n%s:\n", argv[i + 1]); // Name
		
		printf("Value: ");
		scanf(" %i", &values[i]);
		
		printf("Weigth: ");
		scanf(" %i", &weigth[i]);
	}
	
	// Sort argv by value/weigth (bubble sort)
	int temp;
	for (int i = n; i > 1; --i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			if ((values[j] / weigth[j]) > (values[j + 1] / weigth[j + 1]))
			{
				swap(&argv[j + 1], &argv[j + 2]); // Swap names
				
				temp = values[j];
				values[j] = values[j + 1]; // Swap values
				values[j + 1] = temp;
				
				temp = weigth[j];
				weigth[j] = weigth[j + 1]; // Swap weigth
				weigth[j + 1] = temp;
			}
		}
	}
	
	// Output
	printf("\nArray after sorting:\n");
	for (int i = 0; i < n; i++) printf("Item[%i]: %s %i€ %ikg\n", i+1, argv[i+1], values[i], weigth[i]);
	
	// Calc solution
	int bval = 0, bwei = 0;
	printf("\n\nCalculating...\n\n");
	for (int i = 0; i < n; i++)
	{
		if ((bwei + weigth[i]) <= max_weigth)
		{
			printf("%s: %i€ %ikg\n", argv[i + 1], values[i], weigth[i]);
			bwei += weigth[i];
			bval += values[i];
		}
	}
	printf("Best value: %i Best weight: %i\n\n", bval, bwei);

	return 0;
}
