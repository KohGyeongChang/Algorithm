#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "search_binary.h"

extern doublyLinkedList* initializeDoublyLinkedList();
extern void releasedoublyLinkedList(doublyLinkedList*);
extern bool addData(doublyLinkedList*, char* data, int key);
extern bool getData(doublyLinkedList*, char* bufString, int key);
extern doublyLinkedList* popData(doublyLinkedList*, int key);
extern void showAllData(doublyLinkedList*);
extern void showAllData_R(doublyLinkedList*);

int main()
{
	printf("Binary Search Test\n");
	doublyLinkedList* pHead = initializeDoublyLinkedList();
	addData(pHead, "home", 999);
	addData(pHead, "Zero", 222);
	addData(pHead, "appl", 444);
	addData(pHead, "peac", 555);
	addData(pHead, "Star", 111);
	addData(pHead, "pear", 666);
	addData(pHead, "book", 777);
	addData(pHead, "sanb", 333);
	addData(pHead, "mone", 888);
	showAllData(pHead);

	/*
	showAllData_R(pHead);
	char bufString[40] = { 0 };
	bool bRet = -1;
	bRet = getData(pHead, bufString, 111);
	if( bRet ) { 
		printf("getData String : %s\n", bufString);
	}

	bRet = getData(pHead, bufString, 222);
	if( bRet ) { 
		printf("getData String : %s\n", bufString);
	}

	bRet = getData(pHead, bufString, 333);
	if( bRet ) { 
		printf("getData String : %s\n", bufString);
	}

	bRet = getData(pHead,bufString, 234);
	if( bRet ) { 
		printf("getData String : %s\n", bufString);
	}

	printf("\n");
	doublyLinkedList* popedData = popData(pHead, 333);
	if ( popedData ) {
		printf("Poped Data => Key[%d], Data[%s]\n", popedData->key, popedData->data);
	}
	showAllData(pHead);

	popedData = popData(pHead, 777);
	if ( popedData ) {
		printf("Poped Data => Key[%d], Data[%s]\n", popedData->key, popedData->data);
	}
	showAllData(pHead);

	popedData = popData(pHead, 999);
	if ( popedData ) {
		printf("Poped Data => Key[%d], Data[%s]\n", popedData->key, popedData->data);
	}
	showAllData(pHead);

	popedData = popData(pHead, 111);
	if ( popedData ) {
		printf("Poped Data => Key[%d], Data[%s]\n", popedData->key, popedData->data);
	}
	showAllData(pHead);
	showAllData_R(pHead);
	*/
	releasedoublyLinkedList(pHead);

	return 0;
}
