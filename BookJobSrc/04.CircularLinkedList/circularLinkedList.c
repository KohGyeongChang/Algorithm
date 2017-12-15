#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
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

	int cnt = 0;
	while( pTmpNode->pNextNode != pHead) {
		circularLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		printf("releaseList => Key[%d], Data[%s]\n", pTmpNode->key, pTmpNode->data);
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}

	if ( pTmpNode ) {
		printf("releaseList => Key[%d], Data[%s]\n", pTmpNode->key, pTmpNode->data);
		free(pTmpNode);
		pTmpNode = NULL;
	}
}

void releaseNode(circularLinkedList* pNode)
{
	if ( pNode == NULL ) {
		return;
	}
	free(pNode);
}

bool insertData(circularLinkedList* pHead, char* data, int key)
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
	bool bRet = false;
	if ( pHead == NULL ) {
		return bRet;
	}

	if ( pHead->pNextNode == pHead) {
		printf("No Data\n");
		return bRet;
	}

	circularLinkedList* pTmpNode = pHead->pNextNode;
	while( pTmpNode != pHead ) {

		if( pTmpNode->key == key ) {
			bRet = true;
			strcpy(bufString, pTmpNode->data);
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return bRet;
}

circularLinkedList* popData(circularLinkedList* pHead, int key)
{
	if ( pHead->pNextNode == pHead) {
		printf("No Data\n");
		return NULL;
	}

	circularLinkedList* pTmpNode = pHead;
	circularLinkedList* pDeletedNode = NULL;

	while( pTmpNode->pNextNode != pHead ) {

		if( pTmpNode->pNextNode->key == key ) {
			pDeletedNode= pTmpNode->pNextNode;
			pTmpNode->pNextNode = pTmpNode->pNextNode->pNextNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return pDeletedNode;
}

void showAllData(circularLinkedList* pHead)
{
	printf("\n");

	circularLinkedList* pTmpNode = pHead->pNextNode;	

	while( pTmpNode != pHead ) {
		printf("Node Key[%d]:Data[%s]\n", pTmpNode->key, pTmpNode->data);
		circularLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;

	}
	printf("\n");
}

void testCircular(circularLinkedList* pHead)
{
	printf("\n");

	circularLinkedList* pTmpNode = pHead->pNextNode;	

	while( pTmpNode ) {
		sleep(1);
		printf("Node Key[%d]:Data[%s]\n", pTmpNode->key, pTmpNode->data);
		circularLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;

	}
	printf("\n");
}

