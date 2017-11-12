#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/queue.h"

extern nodeData* createNodeData();
extern queueLinkedList* createNode(char* data);
extern queueLinkedList* createHead();
extern queueLinkedList* createTail();
extern queueLinkedList* g_pHead; 
extern queueLinkedList* g_pTail;
extern int initializequeue();
extern void releasequeue();
extern void releaseNode(queueLinkedList* pNode);
extern int pushData(char* data);
extern int popData(char* popedString);
extern void showAllData();

int main()
{
	printf("queue Test\n");
	initializequeue();
	showAllData();
	pushData("Start");
	showAllData();
	pushData("Zero");
	showAllData();
	pushData("Real");
	showAllData();

	char popString[40] = { 0 };
	int nRet = -1;
	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}
	showAllData();
	releasequeue();

	return 0;
}
