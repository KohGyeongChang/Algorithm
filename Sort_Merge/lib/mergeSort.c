#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSort.h"

void displayList(int [], int);

void mergeSort(int inputList[], int inputSize)
{

	int* tmpArr = (int*)calloc(1, sizeof(int) * inputSize );

	free(tmpArr);
}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
