#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

extern stackNode* initializeStack();
extern void releaseStack(stackNode*);
extern int pushData(stackNode*, char* data);
extern int popData(stackNode*, char* popedString);
extern void showAllData(stackNode*);

int main()
{
	printf("Stack Test\n");

	stackNode* pHead = initializeStack();
	pushData(pHead, "Start");
	showAllData(pHead);
	pushData(pHead, "Zero");
	showAllData(pHead);
	pushData(pHead, "Real");
	showAllData(pHead);

	char popString[40] = { 0 };
	int nRet = -1;
	nRet = popData(pHead, popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(pHead, popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(pHead, popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(pHead, popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}
	showAllData(pHead);
	releaseStack(pHead);

	return 0;
}
