#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "search_linear.h"

extern singleLinkedList* initializeSingleLinkedList();
extern void releaseSingleLinkedList(singleLinkedList*);
extern bool insertData(singleLinkedList*, char* data, int key);
extern bool getData(singleLinkedList*, char* bufString, int key);
extern singleLinkedList* popData(singleLinkedList*, int key);
extern void showAllData(singleLinkedList*);

int main()
{
	printf("Single Linked List Test\n");

	singleLinkedList* pHead = initializeSingleLinkedList();
	insertData(pHead, "World", 2);
	insertData(pHead, "Hello", 456);
	insertData(pHead, "Sanbon", 9);

	showAllData(pHead);

	insertData(pHead, "business", 98);
	insertData(pHead, "Computer", 234);
	insertData(pHead, "Notebook", 453);
	insertData(pHead, "CellPhone", 78);
	insertData(pHead, "Real", 22);

	showAllData(pHead);

	char bufString[40] = { 0 };
	bool bRet = getData(pHead, bufString, 2);
	if( bRet ) { 
		printf("GetData => Data[%s]\n", bufString);
	}

	bRet = getData(pHead, bufString, 22);
	if( bRet ) { 
		printf("GetData => Data[%s]\n", bufString);
	}

	bRet = getData(pHead, bufString, 222);
	if( bRet ) { 
		printf("GetData => Data[%s]\n", bufString);
	}

	bRet = getData(pHead, bufString, 234);
	if( bRet ) { 
		printf("GetData => Data[%s]\n", bufString);
	}

	singleLinkedList* popedNode = popData(pHead, 98);
	if ( popedNode ) {
		printf("Key[%d], data[%s]\n", popedNode->key, popedNode->data);
	}
	showAllData(pHead);

	releaseSingleLinkedList(pHead);

	return 0;
}
