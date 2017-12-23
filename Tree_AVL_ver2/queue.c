#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"
#include "tree_avl.h"

queueNode* createNode(treeNode* pTreeNode)
{
	queueNode* pNewNode = (queueNode*)calloc(1, sizeof(queueNode));
	if ( pNewNode == NULL ) {
		printf("New Node Memory Allocation FAIL\n");
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

bool initializeQueue(queueNode** pHead, queueNode** pTail)
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

void releaseQueue(queueNode* pHead)
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

bool enQueue(queueNode* pTail, treeNode* pTreeNode)
{
	if ( pTail == NULL ) {
		return false;
	}

	queueNode* pNewNode= createNode(pTreeNode);
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

treeNode* deQueue(queueNode* pHead, queueNode* pTail)
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
	pPopedNode->pNextNode->pPrevNode = pHead;

	treeNode* pTreeNode = pPopedNode->pTreeNode;
	free(pPopedNode);

	return pTreeNode;
}

void showAllData(queueNode* pHead)
{
	printf("\n");

	queueNode* pTmpNode = pHead;	

	while( pTmpNode ) {
		printf("Node Key[%d]:Data[%s]\n", pTmpNode->pTreeNode->key, pTmpNode->pTreeNode->data);
		queueNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


