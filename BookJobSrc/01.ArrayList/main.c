#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arraylist.h"

extern void printString(char*, const char*, int, char*, ...);
extern arrayNode** initializeList(int);
extern bool releaseList(arrayNode**);
extern int insertData(arrayNode**, int, char*, int);
extern arrayNode* popData(arrayNode**, int, int);
extern void displayList(arrayNode**);

int main()
{
	printString(__FILE__, __func__, __LINE__, "ArrayList Test Program");

	arrayNode** arrayList = initializeList(20);

	if ( arrayList == NULL ) {
		printString(__FILE__, __func__, __LINE__, "Failed To Initialize List");
		return -1;	
	}
	printString(__FILE__, __func__, __LINE__, "Succeeded To Initialize List");

	insertData(arrayList, 9, "Hello", 1);
	displayList(arrayList);

	insertData(arrayList, 1, "Morning", 1);
	displayList(arrayList);

	insertData(arrayList, 10, "World", 1);
	displayList(arrayList);

	insertData(arrayList, 99, "name",  -1);
	displayList(arrayList);

	insertData(arrayList, 4, "Korea",  1);
	displayList(arrayList);

	insertData(arrayList, 48, "Book",  1);
	displayList(arrayList);

	insertData(arrayList, 28, "Desk",  11);
	displayList(arrayList);


	arrayNode* popedNode = NULL;

	popedNode = popData(arrayList, 120, 1);
	if ( popedNode ) {
		printString(__FILE__, __func__, __LINE__, "Front Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
		free(popedNode);
		popedNode = NULL;
	}
	displayList(arrayList);

	popedNode = popData(arrayList, 120, -1);
	if ( popedNode ) {
		printString(__FILE__, __func__, __LINE__, "End Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
		free(popedNode);
		popedNode = NULL;
	}
	displayList(arrayList);

	popedNode = popData(arrayList, 1, 0);
	if ( popedNode ) {
		printString(__FILE__, __func__, __LINE__, "Middle Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
		free(popedNode);
		popedNode = NULL;
	}
	displayList(arrayList);
	insertData(arrayList, 456, "Sanbon",  30);
	displayList(arrayList);

	releaseList(arrayList);

	return 0;
}
