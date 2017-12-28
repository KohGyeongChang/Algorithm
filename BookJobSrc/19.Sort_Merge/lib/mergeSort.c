#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSort.h"

void displayList(int [], int);

void mergeSort(int inputList[], int inputSize)
{
	int* tmpArr = (int*)calloc(1, sizeof(int) * inputSize );
	int firstIdx, secondIdx, tmpIdx;
	int first, second;
	int size;

	int m = 0;
	for( size = 1; size < inputSize; size *= 2 ) {
		first	= -2 * size;
		second	= -1 * size; 

		while ( second + size * 2 < inputSize ) {
			first	+= size * 2;
			second  += size * 2;

			firstIdx = first;
			secondIdx = second;
			tmpIdx = first;

			while ( firstIdx < first + size || ( secondIdx < second + size && secondIdx < inputSize ) ) {
				if ( inputList [ firstIdx ] < inputList[ secondIdx ] ) {
					if ( firstIdx < first + size ) {
						tmpArr[ tmpIdx++ ] = inputList[ firstIdx++ ];
					}
					else {
						tmpArr[ tmpIdx++ ] = inputList[ secondIdx++ ];
					}
				}
				else {
					if ( secondIdx < second + size && secondIdx < inputSize ) {
						tmpArr[ tmpIdx++ ] = inputList[ secondIdx++ ];
					}
					else {
						tmpArr[ tmpIdx++ ] = inputList[ firstIdx++ ];
					}
				}
			}
			m = tmpIdx;
		}

		if ( second + size * 2 >= inputSize && m < inputSize ) {
			for ( int i = m; i < inputSize; ++i ) {
				tmpArr[ i ] = inputList[ i ];
			}
		}

		for ( int i = 0; i < inputSize; ++i ) {
			inputList[ i ] = tmpArr[ i ];
		}
		displayList(inputList, inputSize);
	}

	free(tmpArr);
}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
