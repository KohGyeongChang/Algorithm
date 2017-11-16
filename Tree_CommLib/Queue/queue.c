#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"


queueNode* createNode(treeNode* pTreeNode)
{
	queueNode* pNewNode = (queueNode*)calloc(1, sizeof(queueNode));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	pNewNode->pTreeNode = pTreeNode;

	return pNewNode;
}

queueNode* createHead()
{
	// Caller Checks if pointer is NULL
	queueNode* pHead = createNode(NULL);
	return pHead;
}


queueNode* createTail()
{
	// Caller Checks if pointer is NULL
	queueNode* pTail= createNode(NULL);
	return pTail;
}

queueNode* g_pHead; 
queueNode* g_pTail;

int initializeQueue()
{
	g_pHead = createHead();
	if ( g_pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return -1;
	}

	g_pTail = createTail();
	if ( g_pTail == NULL ) {
		printf("CreateTail FAIL\n"); 
		return -1;
	}

	g_pHead->pNextNode = g_pTail;
	g_pTail->pNextNode = NULL;

	return 0;
}

void releaseQueue()
{
	queueNode* pTmpNode = g_pHead;	

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

int isQueueEmpty()
{
	if ( g_pHead->pNextNode == g_pTail ) {
		return 1;
	}

	return 0;
}

int pushData(treeNode* pTreeNode)
{
	queueNode* pNewNode= createNode(pTreeNode);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	queueNode* pTmpNode = g_pHead;

	while( 1 ) {

		if ( pTmpNode->pNextNode == g_pTail ) {

			pNewNode->pNextNode = pTmpNode->pNextNode;
			pTmpNode->pNextNode = pNewNode;;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}

	return 0;

}

treeNode* popData()
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return NULL;
	}

	queueNode* pPopedNode = g_pHead->pNextNode; 
	g_pHead->pNextNode = pPopedNode->pNextNode;

	treeNode* pTreeNode = pPopedNode->pTreeNode;
	releaseNode(pPopedNode);

	return pTreeNode;
}

void showAllData()
{
	printf("\n");

	queueNode* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%c]\n", pTmpNode->pTreeNode->pData->data);
		queueNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


