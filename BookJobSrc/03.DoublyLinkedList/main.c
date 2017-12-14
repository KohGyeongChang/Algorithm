#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "doublyLinkedList.h"

extern doublyLinkedList* initializeDoublyLinkedList();
extern void releasedoublyLinkedList(doublyLinkedList*);
extern bool insertData(doublyLinkedList*, char* data, int key);
extern bool getData(doublyLinkedList*, char* bufString, int key);
extern doublyLinkedList* popData(doublyLinkedList*, int key);
extern void showAllData(doublyLinkedList*);
extern void showAllData_R(doublyLinkedList*);

int main()
{
	printf("Single Linked List Test\n");
	doublyLinkedList* pHead = initializeDoublyLinkedList();
	insertData(pHead, "Star", 111);
	insertData(pHead, "Zero", 222);
	insertData(pHead, "sanb", 333);
	insertData(pHead, "appl", 444);
	insertData(pHead, "peac", 555);
	insertData(pHead, "pear", 666);
	insertData(pHead, "book", 777);
	insertData(pHead, "mone", 888);
	insertData(pHead, "home", 999);
	showAllData(pHead);
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
	releasedoublyLinkedList(pHead);

	return 0;
}
