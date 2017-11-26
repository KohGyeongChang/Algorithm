#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectionSort.h"

void selectionSort(int inputList[], int inputSize)
{
	int indexOfMinValue;	
	for ( int i = 0 ; i < inputSize; ++i ) {
		indexOfMinValue = i;

		for ( int j = i + 1; j < inputSize; ++j ) {
			if ( inputList[j] < inputList[indexOfMinValue] ) {
				indexOfMinValue = j;
			}

		}

		int tmp = inputList[i];
		inputList[i] = inputList[indexOfMinValue];
		inputList[indexOfMinValue] = tmp;
	}

}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
