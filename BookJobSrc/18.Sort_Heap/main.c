#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./lib/heapSort.h"

extern void heapSort(int [], int);
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
	printf("Heap Sort Test\n");

	int inputList[LIST_SIZE +1] = { 0 };
	makeList(inputList, LIST_SIZE);
	displayList(inputList, LIST_SIZE+1);
	
	printf("Start Heap Sort\n");
	heapSort(inputList, LIST_SIZE+1);
	displayList(inputList, LIST_SIZE+1);
	

	return 0;
}
