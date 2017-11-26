#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertionSort.h"

void displayList(int [], int);
void insertionSort(int inputList[], int inputSize)
{
	for ( int i = 0 ; i < inputSize; ++i ) {

		int tmp = inputList[i];
		int j = i;

		while ( inputList[ j - 1 ] > tmp && j > 0 ) {
			inputList[ j  ] = inputList[ j - 1 ];
			j--;	

		}

		inputList[ j ] = tmp;
		displayList(inputList, inputSize);
	}

}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
