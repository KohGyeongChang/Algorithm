#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

extern int initializequeue(queueNode**, queueNode**);
extern void releasequeue(queueNode*);
extern bool enQueue(queueNode* pTail, int Key, char* data);
extern queueNode* deQueue(queueNode* pHead, queueNode* pTail);
extern void showAllData(queueNode* pHead);
extern bool hasQueueData(queueNode*, queueNode*);

int main()
{
	printf("queue Test\n");

	queueNode* pHead = NULL;
	queueNode* pTail = NULL;

	initializequeue(&pHead, &pTail);

	showAllData(pHead);
	if ( hasQueueData(pHead, pTail)) {
		printf("Queue has Data\n");
	}
	else {
		printf("Queue has NO Data\n");
	}


	enQueue(pTail,111, "Start");
	showAllData(pHead);

	enQueue(pTail,222, "Zero");
	showAllData(pHead);

	enQueue(pTail, 333, "Real");
	showAllData(pHead);

	enQueue(pTail, 444, "Jeju");
	showAllData(pHead);

	if ( hasQueueData(pHead, pTail)) {
		printf("Queue has Data\n");
	}
	else {
		printf("Queue has NO Data\n");
	}

	queueNode* popedNode = NULL;
	popedNode = deQueue(pHead, pTail);
	if( popedNode ) { 
		printf("Poped Node Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	popedNode = deQueue(pHead, pTail);
	if( popedNode ) { 
		printf("Poped Node Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	popedNode = deQueue(pHead, pTail);
	if( popedNode ) { 
		printf("Poped Node Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	popedNode = deQueue(pHead, pTail);
	if( popedNode ) { 
		printf("Poped Node Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	popedNode = deQueue(pHead, pTail);
	if( popedNode ) { 
		printf("Poped Node Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}

	showAllData(pHead);

	if ( hasQueueData(pHead, pTail)) {
		printf("Queue has Data\n");
	}
	else {
		printf("Queue has NO Data\n");
	}

	releasequeue(pHead);

	return 0;
}
