#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

queueNode* createNode(char* data)
{
	queueNode* pNewNode = (queueNode*)calloc(1, sizeof(queueNode));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	memcpy(pNewNode->data, data, strlen(data) );
	return pNewNode;
}

queueNode* createHead()
{
	// Caller Checks if pointer is NULL
	queueNode* pHead = createNode("HEAD");
	return pHead;
}


queueNode* initializequeue()
{
	queueNode* pHead = createHead();
	if ( pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return NULL;
	}

	pHead->pNextNode = NULL;

	return pHead;
}

void releasequeue(queueNode* pHead)
{
	queueNode* pTmpNode = pHead;	

	while( pTmpNode ) {
		queueNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(queueNode* pNode)
{
	if ( pNode == NULL ) {
		return;
	}
	free(pNode);
}

int isQueueEmpty(queueNode* pHead)
{
	if ( pHead->pNextNode == NULL) {
		return 1;
	}

	return 0;
}

int pushData(queueNode* pHead, char* data)
{
	queueNode* pNewNode= createNode(data);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	queueNode* pTmpNode = pHead;

	while( 1 ) {

		if ( pTmpNode->pNextNode == NULL) {

			pNewNode->pNextNode = pTmpNode->pNextNode;
			pTmpNode->pNextNode = pNewNode;;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}

	return 0;

}

int popData(queueNode* pHead, char* popedString)
{
	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return -1;
	}

	queueNode* pPopedNode = pHead->pNextNode; 
	pHead->pNextNode = pPopedNode->pNextNode;

	strcpy(popedString, pPopedNode->data);
	releaseNode(pPopedNode);

	return 0;
}

void showAllData(queueNode* pHead)
{
	printf("\n");

	queueNode* pTmpNode = pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->data);
		queueNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


