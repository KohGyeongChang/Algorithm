#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubbleSort.h"

void displayList(int [], int);
void bubbleSort(int inputList[], int inputSize)
{

	for ( int i = inputSize; i > 0 ; --i ) {
		for ( int j = 1; j < i; ++j ) {
			if ( inputList[ j - 1 ] > inputList[ j ] ) {
				int tmp = inputList[ j ];
				inputList[ j ] = inputList[ j - 1];
				inputList[ j - 1 ] = tmp;
			}

		}
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
