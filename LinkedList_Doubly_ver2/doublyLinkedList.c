#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "doublyLinkedList.h"


doublyLinkedList* createNode(char* data, int key)
{
	doublyLinkedList* pNewNode = (doublyLinkedList*)calloc(1, sizeof(doublyLinkedList));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	memcpy(pNewNode->data, data, strlen(data) );

	pNewNode->key = key;

	return pNewNode;
}

doublyLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	doublyLinkedList* pHead = createNode("HEAD", 1);
	return pHead;
}


doublyLinkedList* initializeDoublyLinkedList()
{
	doublyLinkedList* pHead = createHead();
	if ( pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return NULL;
	}

	pHead->pNextNode = NULL;
	pHead->pPrevNode = NULL;

	return pHead;
}

void releasedoublyLinkedList(doublyLinkedList* pHead)
{
	doublyLinkedList* pTmpNode = pHead;	

	while( pTmpNode ) {

		doublyLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(doublyLinkedList* pNode)
{
	if ( pNode == NULL ) {
		return;
	}
	free(pNode);
}

bool addData(doublyLinkedList* pHead, char* data, int key)
{
	doublyLinkedList* pNewNode= createNode(data, key);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return false;
	}

	doublyLinkedList* pTmpNode = pHead;

	while( 1 ) {

		if ( pTmpNode->pNextNode == NULL) {
			pNewNode->pNextNode = pTmpNode->pNextNode;
			pNewNode->pPrevNode = pTmpNode;
			pTmpNode->pNextNode = pNewNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}

	return true;
}

bool getData(doublyLinkedList* pHead, char* bufString, int key)
{
	bool bRet = false;
	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return bRet;
	}

	doublyLinkedList* pTmpNode = pHead;

	while( pTmpNode ) {

		if( pTmpNode->key == key ) {
			strcpy(bufString, pTmpNode->data);
			bRet = true;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return bRet;
}

doublyLinkedList* popData(doublyLinkedList* pHead, int key)
{
	if ( pHead == NULL ){
		return NULL;	
	}

	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return NULL;
	}

	doublyLinkedList* pTmpNode = pHead;
	doublyLinkedList* pDeletedNode = NULL;

	while( pTmpNode->pNextNode ) {
	
		pDeletedNode = NULL;
		if( pTmpNode->pNextNode->key == key ) {
			pDeletedNode = pTmpNode->pNextNode;
			if ( pDeletedNode->pNextNode ){
				pDeletedNode->pNextNode->pPrevNode = pDeletedNode->pPrevNode;
			}
			pTmpNode->pNextNode = pDeletedNode->pNextNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return pDeletedNode;
}

void showAllData(doublyLinkedList* pHead)
{
	if ( pHead == NULL ) {
		return;
	}

	doublyLinkedList* pTmpNode = pHead->pNextNode;	

	while( pTmpNode ) {
		printf("Node Key[%d] : Data[%s]\n",pTmpNode->key, pTmpNode->data);
		doublyLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


void showAllData_R(doublyLinkedList* pHead)
{
	printf("Reverse From EndNode ...........\n");

	if ( pHead == NULL ) {
		return;
	}

	doublyLinkedList* pTmpNode = pHead->pNextNode;	
	doublyLinkedList* pEndNode = NULL;

	while( pTmpNode ) {
		doublyLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
			pEndNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}

	pTmpNode = pEndNode;
	while( pTmpNode != pHead) {
		printf("Node Key[%d] : Data[%s]\n",pTmpNode->key, pTmpNode->data);
		doublyLinkedList* pTmpPrevNode = NULL;	
		if ( pTmpNode->pPrevNode ) {
			pTmpPrevNode = pTmpNode->pPrevNode;
		}
		pTmpNode = pTmpPrevNode;
	}
	printf("\n");
}
