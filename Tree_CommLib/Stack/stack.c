#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"


stackNode* createNode(treeNode* pTreeNode)
{
	stackNode* pNewNode = (stackNode*)calloc(1, sizeof(stackNode));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	/*
	if ( pNode == NULL ) {
		printf("Tree Node NULL\n");
		return NULL;
	}
	*/

	pNewNode->pTreeNode = pTreeNode;

	return pNewNode;
}

stackNode* createHead()
{
	// Caller Checks if pointer is NULL
	stackNode* pHead = createNode(NULL);
	return pHead;
}


stackNode* createTail()
{
	// Caller Checks if pointer is NULL
	stackNode* pTail= createNode(NULL);
	return pTail;
}

stackNode* g_pHead; 
stackNode* g_pTail;

bool initializeStack()
{
	g_pHead = createHead();
	if ( g_pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return false;
	}

	g_pTail = createTail();
	if ( g_pTail == NULL ) {
		printf("CreateTail FAIL\n"); 
		return false;
	}

	g_pHead->pNextNode = g_pTail;
	g_pTail->pNextNode = NULL;

	return true;
}

void releaseStack()
{
	stackNode* pTmpNode = g_pHead;	

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

bool stackHasData()
{
	if ( g_pHead->pNextNode == g_pTail ) {
		return false;
	}

	return true; 
}

bool pushData(treeNode* pTreeNode)
{
	stackNode* pNewNode= createNode(pTreeNode);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return false;
	}

	pNewNode->pNextNode = g_pHead->pNextNode;
	g_pHead->pNextNode = pNewNode;

	return true;
}

treeNode* popData()
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return NULL;
	}

	stackNode* pPopedNode = g_pHead->pNextNode; 
	g_pHead->pNextNode = pPopedNode->pNextNode;

	treeNode* pTreeNode = pPopedNode->pTreeNode;
	releaseNode(pPopedNode);

	return pTreeNode;
}

void showAllData()
{
	printf("\n");

	stackNode* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		printf("Tree Node Data : [%c]\n", pTmpNode->pTreeNode->pData->data);
		stackNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


