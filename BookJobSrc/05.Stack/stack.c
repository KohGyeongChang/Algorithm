#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

stackNode* createNode(char* data)
{
	stackNode* pNewNode = (stackNode*)calloc(1, sizeof(stackNode));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	memcpy(pNewNode->data, data, strlen(data) );
	return pNewNode;
}

stackNode* createHead()
{
	// Caller Checks if pointer is NULL
	stackNode* pHead = createNode("HEAD");
	return pHead;
}

stackNode* initializeStack()
{
	stackNode* pHead = createHead();
	if ( pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return NULL;
	}
	pHead->pNextNode = NULL;

	return pHead;
}

void releaseStack(stackNode* pHead)
{
	stackNode* pTmpNode = pHead;	

	while( pTmpNode ) {
		stackNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(stackNode* pNode)
{
	if ( pNode == NULL ) {
		return;
	}

	free(pNode);
}

int isStackEmpty(stackNode* pHead)
{
	if ( pHead->pNextNode == NULL) {
		return 1;
	}

	return 0;
}

int pushData(stackNode* pHead, char* data)
{
	stackNode* pNewNode= createNode(data);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	pNewNode->pNextNode = pHead->pNextNode;
	pHead->pNextNode = pNewNode;

	return 0;

}

int popData(stackNode* pHead, char* popedString)
{
	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return -1;
	}

	stackNode* pPopedNode = pHead->pNextNode; 
	pHead->pNextNode = pPopedNode->pNextNode;

	strcpy(popedString, pPopedNode->data);
	releaseNode(pPopedNode);

	return 0;
}

void showAllData(stackNode* pHead)
{
	printf("\n");

	stackNode* pTmpNode = pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->data);
		stackNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


