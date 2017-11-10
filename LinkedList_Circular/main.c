#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedList.h"

extern nodeData* createNodeData();
extern circularLinkedList* createNode(char* data, int key);
extern circularLinkedList* createHead();
extern circularLinkedList* createTail();
extern circularLinkedList* g_pHead; 
extern circularLinkedList* g_pTail;
extern int initializecircularLinkedList();
extern void releasecircularLinkedList();
extern void releaseNode(circularLinkedList* pNode);
extern int addData(char* data, int key);
extern int getData(char* bufString, int key);
extern int deleteData(int key);
extern void showAllData();


int main()
{
	printf("Single Linked List Test\n");
	initializecircularLinkedList();
	addData("Start", 2);
	addData("Zero", 22);
	addData("Real", 222);
	showAllData();

	char bufString[40] = { 0 };
	int nRet = -1;
	nRet = getData(bufString, 2);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 22);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 222);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 234);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	deleteData(222);
	showAllData();
	releasecircularLinkedList();

	return 0;
}
