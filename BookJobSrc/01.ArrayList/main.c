#include <stdio.h>
#include <stdbool.h>
#include "arraylist.h"

extern void printString(char*, const char*, int, char*, ...);
extern arrayNode** initializeList(int);
extern bool releaseList(arrayNode**);
extern bool insertData(arrayNode**, int, char*, int);
extern arrayNode* popData(arrayNode**, int, int);
extern void displayList(arrayNode**);

int main()
{
	printString(__FILE__, __func__, __LINE__, "ArrayList Test Program");

	arrayNode** arrayList = initializeList(30);
	if ( arrayList == NULL ) {
		printString(__FILE__, __func__, __LINE__, "Failed To Initialize List");
		return -1;	
	}
	printString(__FILE__, __func__, __LINE__, "Succeeded To Initialize List");

	insertData(arrayList, 9, "Hello", 1);
	insertData(arrayList, 1, "Morning", 1);
	insertData(arrayList, 10, "World", 1);
	insertData(arrayList, 99, "name",  -1);
	insertData(arrayList, 4, "Korea",  1);
	insertData(arrayList, 48, "Book",  1);
	insertData(arrayList, 28, "Desk",  11);
	insertData(arrayList, 100, "Linux",  -1);
	insertData(arrayList, 54, "Pencil",  1);
	insertData(arrayList, 120, "Windows",  3);
	displayList(arrayList);

	arrayNode* popedNode = NULL;

	popedNode = popData(arrayList, 120, 1);
	printString(__FILE__, __func__, __LINE__, "Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);

	displayList(arrayList);

	popedNode = popData(arrayList, 120, -1);
	printString(__FILE__, __func__, __LINE__, "Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
	displayList(arrayList);

	popedNode = popData(arrayList, 1, 0);
	printString(__FILE__, __func__, __LINE__, "Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
	displayList(arrayList);

	popedNode = popData(arrayList, 48, 0);
	printString(__FILE__, __func__, __LINE__, "Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
	displayList(arrayList);

	popedNode = popData(arrayList, 28, 0);
	printString(__FILE__, __func__, __LINE__, "Poped Node Value => Key[%d], Data[%s]", popedNode->key, popedNode->data);
	displayList(arrayList);

	insertData(arrayList, 456, "Sanbon",  30);
	displayList(arrayList);

	releaseList(arrayList);

	return 0;
}
