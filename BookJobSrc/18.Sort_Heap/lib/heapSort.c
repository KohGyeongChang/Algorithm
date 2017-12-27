#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapSort.h"

void displayList(int [], int);

void upHeap(int inputList[], int Nth)
{
	int elemToMove = inputList[ Nth ];
	while ( inputList[ Nth / 2 ] <= elemToMove ) {
		inputList[ Nth ] = inputList[ Nth / 2]; 
		Nth /= 2;

		if ( Nth == 0 ) break;
	}
	inputList[ Nth ] = elemToMove;
}

void downHeap( int inputList[], int heapSize, int Nth)
{
	int elemToMove = inputList[ Nth ];
	int tmp;
	while ( Nth <= heapSize / 2 ) {
		tmp = Nth * 2;
		if ( (tmp < heapSize) && (inputList[ tmp ] < inputList[ tmp + 1 ]) ) {
			tmp++;
		}

		if ( elemToMove >= inputList[ tmp ] ) {
			break;
		}
		inputList[ Nth ] = inputList[ tmp ];
		Nth = tmp;
	}
	inputList[ Nth ] = elemToMove;
}

void insertToHeap(int inputList[], int* heapSize, int inputValue)
{
	inputList[++(*heapSize)] = inputValue;
	upHeap(inputList, *heapSize);
}

int removeFromHeap(int inputList[], int* heapSize)
{
	int elemToExtract = inputList[ 1 ];
	inputList[ 1 ] = inputList[(*heapSize)--]; 
	downHeap(inputList, *heapSize, 1);
	return elemToExtract;
}

void heapSort(int inputList[], int inputSize)
{
	int heapSize = 0;
	for( int i = 1; i <= inputSize; ++i ) {
		insertToHeap(inputList, &heapSize, inputList[i]);
	}

	for( int j = heapSize; j >= 1; j-- ) {
		inputList[j] = removeFromHeap(inputList, &heapSize);
	}
}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
