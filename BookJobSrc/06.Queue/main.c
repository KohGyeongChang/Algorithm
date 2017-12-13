#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

extern queueNode* initializequeue();
extern void releasequeue(queueNode* );
extern int pushData(queueNode*, char* data);
extern int popData(queueNode*, char* popedString);
extern void showAllData(queueNode*);

int main()
{
	printf("Queue Test\n");

	queueNode* pHead = initializequeue();
	showAllData(pHead);

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
	releasequeue(pHead);

	return 0;
}
