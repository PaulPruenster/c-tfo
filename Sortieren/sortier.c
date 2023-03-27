#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10000
#define MAXN 100

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[])
{
   int i, j;
   for (i = 0; i < SIZE-1; i++)      
       for (j = 0; j < SIZE-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main (void)
{
	int elemente[SIZE];
	
	printf("Sortiere: int elemente [%i] (Elemente 0 - %i)\n", SIZE, MAXN);
	
	printf("Vorher: \n");
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		elemente[i] = rand() % MAXN;
		printf(" %i", elemente[i]);
	}
	
	printf("\nNachher: \n");	
	
	bubbleSort(elemente);	
	
	// nachher
	for (int i = 0; i < SIZE; i++) 
		printf(" %i", elemente[i]);
	printf("\n");
}
