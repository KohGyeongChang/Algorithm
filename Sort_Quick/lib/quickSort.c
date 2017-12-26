#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quickSort.h"

void displayList(int [], int);
void quickSort(int inputList[], int inputSize)
{
	if ( inputSize <= 1 ) return;

	int pivot = inputList[ inputSize - 1 ];
	int start = -1;;
	int end	= inputSize - 1;
	int tmp;

	while ( 1 ) {
		while ( inputList[ ++start ] < pivot );
		while ( inputList[ --end ] > pivot ) ;

		if ( start >= end ) break;

		tmp = inputList[ start ];
		inputList[ start ] = inputList[ end ];
		inputList[ end ] = tmp;

		displayList(inputList, inputSize);
	}

	tmp = inputList[ start ];
	inputList[ start ] = inputList[ inputSize - 1 ];
	inputList[ inputSize - 1 ] = tmp;

	quickSort( inputList, start ); 
	quickSort( inputList + start + 1, inputSize - ( start + 1 ) ); 
}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
