#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circularLinkedList.h"

extern circularLinkedList* initializecircularLinkedList();
extern void releasecircularLinkedList(circularLinkedList*);
extern bool insertData(circularLinkedList*, char* data, int key);
extern bool getData(circularLinkedList*, char* bufString, int key);
extern circularLinkedList* popData(circularLinkedList*, int key);
extern void showAllData(circularLinkedList* );
extern void testCircular(circularLinkedList* );


int main()
{
	printf("Doubly Linked List Test\n");

	circularLinkedList* pHead = initializecircularLinkedList();
	insertData(pHead, "Start",1);
	insertData(pHead, "Zero", 2);
	insertData(pHead, "Real", 22);
	insertData(pHead, "sanb", 222);
	insertData(pHead, "jeju", 334);
	insertData(pHead, "bowl", 564);
	insertData(pHead, "Prog", 467);
	insertData(pHead, "Nara", 765);
	showAllData(pHead);

	char bufString[40] = { 0 };
	bool bRet = false;
	bRet = getData(pHead, bufString, 2);
	if( bRet ) { 
		printf("getData : %s\n", bufString);
	}

	memset(bufString, 0, sizeof(bufString));
	bRet = getData(pHead, bufString, 22);
	if( bRet ) { 
		printf("getData : %s\n", bufString);
	}

	memset(bufString, 0, sizeof(bufString));
	bRet = getData(pHead, bufString, 222);
	if( bRet ) { 
		printf("getData : %s\n", bufString);
	}

	memset(bufString, 0, sizeof(bufString));
	bRet = getData(pHead, bufString, 234);
	if( bRet ) { 
		printf("Data String : %s\n", bufString);
	}

	circularLinkedList* popedNode = popData(pHead, 564);
	if ( popedNode ) {
		printf("\nPoped Data Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	showAllData(pHead);


//	testCircular(pHead);

	releasecircularLinkedList(pHead);

	return 0;
}
