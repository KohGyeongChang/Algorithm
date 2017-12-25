#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shellSort.h"

void displayList(int [], int);
void shellSort(int inputList[], int inputSize)
{
	for( int h = inputSize / 2 ; h > 0 ; h /= 2 ) {
		for ( int i = 0; i < h; ++i ) {
			for ( int j = i + h ; j < inputSize; j += h ) {
				int k = inputList[ j ];
				int M = j;

				while ( inputList[ M - h ] > k && M >= h ) {
					inputList[ M ] = inputList[ M - h ];
					M -= h;
				}

				inputList[ M ] = k;
				displayList(inputList, inputSize);
			}
		}
	}

}

void displayList(int inputList[], int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		printf("%04d ", inputList[i]);
	}
	printf("\n");

}
