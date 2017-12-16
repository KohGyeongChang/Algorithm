#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

queueNode* createNode(int Key, char* data)
{
	queueNode* pNewNode = (queueNode*)calloc(1, sizeof(queueNode));
	if ( pNewNode == NULL ) {
		printf("New Node Memory Allocation FAIL\n");
		return NULL;
	}

	pNewNode->key = Key;
	memcpy(pNewNode->data, data, strlen(data) );

	return pNewNode;
}

queueNode* createHead()
{
	// Caller Checks if pointer is NULL
	queueNode* pHead = createNode(0, "HEAD");
	return pHead;
}


queueNode* createTail()
{
	// Caller Checks if pointer is NULL
	queueNode* pTail= createNode(0, "TAIL");
	return pTail;
}

bool initializequeue(queueNode** pHead, queueNode** pTail)
{
	*pHead = createHead();
	if ( *pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return false;
	}

	*pTail = createTail();
	if ( *pTail == NULL ) {
		printf("CreateTail FAIL\n"); 
		return false;
	}

	(*pHead)->pNextNode = *pTail;
	(*pHead)->pPrevNode = NULL;
	(*pTail)->pNextNode = NULL;
	(*pTail)->pPrevNode = (*pHead);

	return true;
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

bool hasQueueData(queueNode* pHead, queueNode* pTail)
{
	if ( pHead->pNextNode == pTail ) {
		return false;
	}

	return true;
}

bool enQueue(queueNode* pTail, int Key, char* data)
{
	if ( pTail == NULL ) {
		return false;
	}

	queueNode* pNewNode= createNode(Key, data);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return false;
	}

	pTail->pPrevNode->pNextNode = pNewNode;
	pNewNode->pNextNode = pTail;
	pNewNode->pPrevNode = pTail->pPrevNode;
	pTail->pPrevNode = pNewNode;

	return true;

}

queueNode* deQueue(queueNode* pHead, queueNode* pTail)
{
	if ( pHead == NULL ) {
		return false;
	}

	if ( pHead->pNextNode == pTail) {
		printf("No DATA\n");
		return false;
	}

	queueNode* pPopedNode = pHead->pNextNode; 
	pHead->pNextNode = pPopedNode->pNextNode;

	return pPopedNode;
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


