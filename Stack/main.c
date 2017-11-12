#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/stack.h"

extern nodeData* createNodeData();
extern stackNode* createNode(char* data);
extern stackNode* createHead();
extern stackNode* createTail();
extern stackNode* g_pHead; 
extern stackNode* g_pTail;
extern int initializeStack();
extern void releaseStack();
extern void releaseNode(stackNode* pNode);
extern int pushData(char* data);
extern int popData(char* popedString);
extern void showAllData();

int main()
{
	printf("Stack Test\n");
	initializeStack();
	pushData("Start");
	pushData("Zero");
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
	releaseStack();

	return 0;
}
