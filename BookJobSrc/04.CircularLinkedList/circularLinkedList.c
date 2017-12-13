#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circularLinkedList.h"


circularLinkedList* createNode(char* data, int key)
{
	circularLinkedList* pNewNode = (circularLinkedList*)calloc(1, sizeof(circularLinkedList));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	memcpy(pNewNode->data, data, strlen(data) );
	pNewNode->key = key;
	return pNewNode;
}

circularLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	circularLinkedList* pHead = createNode("HEAD", 1);
	return pHead;
}

circularLinkedList* initializecircularLinkedList()
{
	circularLinkedList* pHead = createHead();
	if ( pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return NULL;
	}

	pHead->pNextNode = pHead;

	return pHead;
}

void releasecircularLinkedList(circularLinkedList* pHead)
{
	circularLinkedList* pTmpNode = pHead;	

	while( pTmpNode ) {
		circularLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(circularLinkedList* pNode)
{
	if ( pNode == NULL ) {
		return;
	}
	free(pNode);
}

bool addData(circularLinkedList* pHead, char* data, int key)
{
	circularLinkedList* pNewNode= createNode(data, key);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return false;
	}

	circularLinkedList* pTmpNode = pHead;

	while( 1 ) {

		if ( pTmpNode->pNextNode == pHead) {
			pNewNode->pNextNode = pTmpNode->pNextNode;
			pTmpNode->pNextNode = pNewNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return true;
}

bool getData(circularLinkedList* pHead, char* bufString, int key)
{
	if ( pHead == NULL ) {
		return false;
	}

	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return false;
	}

	circularLinkedList* pTmpNode = pHead->pNextNode;
	while( pTmpNode ) {

		if( pTmpNode->key == key ) {
			strcpy(bufString, pTmpNode->data);
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return true;
}

circularLinkedList* popData(circularLinkedList* pHead, int key)
{
	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return NULL;
	}

	circularLinkedList* pTmpNode = pHead;
	circularLinkedList* pDeletedNode = NULL;

	while( pTmpNode->pNextNode ) {

		if( pTmpNode->pNextNode->key == key ) {
			pDeletedNode= pTmpNode->pNextNode;
			pTmpNode->pNextNode = pTmpNode->pNextNode->pNextNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return pDeletedNode;
}

void showAllData(circularLinkedList* pHead, int nCnt)
{
	printf("\n");

	circularLinkedList* pTmpNode = pHead->pNextNode;	

	int cnt = nCnt;
	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->data);
		circularLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;

	}
	printf("\n");
}


