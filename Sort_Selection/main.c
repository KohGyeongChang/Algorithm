#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./lib/selectionSort.h"

extern void selectionSort(int [], int);
extern void displayList(int [], int);

#define LIST_SIZE 20
 
bool checkSameValue(int inputList[], int listSize, int inputValue)
{
	for ( int i  = 0; i < listSize; ++i ) {
		if ( inputList[i] == inputValue ) {
			return true;
		}
	}

	return false;
}

void makeList(int inputList[], int listSize)
{
	int index = 0, tmpValue;

	srand((unsigned)time(NULL));

	while ( index < LIST_SIZE ) {
		tmpValue = rand() % ( LIST_SIZE * 5 );
		if ( checkSameValue(inputList, listSize, tmpValue) ) {
			continue;
		}

		inputList[index++] = tmpValue;
	}


}

int main()
{
	printf("Selection Sort Test\n");

	int inputList[LIST_SIZE] = { 0 };
	makeList(inputList, LIST_SIZE);
	displayList(inputList, LIST_SIZE);
	
	printf("Start Selection Sort\n");
	selectionSort(inputList, LIST_SIZE);
	

	return 0;
}
