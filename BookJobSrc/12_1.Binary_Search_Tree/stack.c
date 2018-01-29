#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"


stackNode* createNode(treeNode* pTreeNode)
{
	stackNode* pNewNode = (stackNode*)calloc(1, sizeof(stackNode));
	if ( pNewNode == NULL ) {
		printf("New Node Memory Allocation FAIL\n");
		return NULL;
	}
	pNewNode->pTreeNode = pTreeNode;
	return pNewNode;
}

stackNode* createHead()
{
	stackNode* pHead = createNode(NULL);
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

bool hasStackData(stackNode* pHead)
{
	if ( pHead->pNextNode == NULL) {
		return false;
	}

	return true;
}

bool pushData(stackNode* pHead, treeNode* pTreeNode)
{
	stackNode* pNewNode= createNode(pTreeNode);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return false;
	}
	pNewNode->pNextNode = pHead->pNextNode;
	pHead->pNextNode = pNewNode;

	return true;
}

treeNode* popData(stackNode* pHead)
{
	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return NULL;
	}
	stackNode* pPopedNode = pHead->pNextNode; 
	pHead->pNextNode = pPopedNode->pNextNode;
	treeNode* pTreeNode = pPopedNode->pTreeNode;
	free(pPopedNode);

	return pTreeNode;
}

void showAllData(stackNode* pHead)
{
	printf("\n");

	stackNode* pTmpNode = pHead->pNextNode;	

	while( pTmpNode ) {
		printf("Node Key[%d]:Data[%s]\n", pTmpNode->pTreeNode->key, pTmpNode->pTreeNode->data);
		stackNode* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


