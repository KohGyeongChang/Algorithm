#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circularLinkedList.h"

extern circularLinkedList* initializecircularLinkedList();
extern void releasecircularLinkedList(circularLinkedList*);
extern bool addData(circularLinkedList*, char* data, int key);
extern bool getData(circularLinkedList*, char* bufString, int key);
extern circularLinkedList* popData(circularLinkedList*, int key);
extern void showAllData(circularLinkedList*, int );


int main()
{
	printf("Doubly Linked List Test\n");

	circularLinkedList* pHead = initializecircularLinkedList();
	addData(pHead, "Start", 2);
	addData(pHead, "Zero", 22);
	addData(pHead, "Real", 222);
	showAllData(pHead, 3);

	char bufString[40] = { 0 };
	bool bRet = false;
	bRet = getData(pHead, bufString, 2);
	if( bRet ) { 
		printf("Data String : %s\n", bufString);
	}

	bRet = getData(pHead, bufString, 22);
	if( bRet ) { 
		printf("Data String : %s\n", bufString);
	}

	bRet = getData(pHead, bufString, 222);
	if( bRet ) { 
		printf("Data String : %s\n", bufString);
	}

	bRet = getData(pHead, bufString, 234);
	if( bRet ) { 
		printf("Data String : %s\n", bufString);
	}

	popData(pHead, 222);
	showAllData(pHead, 3);
	releasecircularLinkedList(pHead);

	return 0;
}
