#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singleLinkedList.h"

singleLinkedList* createNode(char* data, int key)
{
	singleLinkedList* pNewNode = (singleLinkedList*)calloc(1, sizeof(singleLinkedList));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	memcpy(pNewNode->data, data, strlen(data) );
	pNewNode->key = key;

	return pNewNode;
}

singleLinkedList* initializeSingleLinkedList()
{
	singleLinkedList* pHead = NULL; 
	pHead = createNode("Head", 1);
	if ( pHead == NULL ) {
		printf("CreateHead FAIL\n"); 
		return NULL;
	}

	pHead->pNextNode = NULL;

	return pHead;
}

void releaseSingleLinkedList(singleLinkedList* pHead)
{
	singleLinkedList* pTmpNode = pHead;	

	while( pTmpNode ) {
		singleLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}


int insertData(singleLinkedList* pHead, char* data, int key)
{
	if ( pHead == NULL ) {
		return -1;
	}

	singleLinkedList* pNewNode= createNode(data, key);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	singleLinkedList* pTmpNode = pHead;
	while ( 1 ) {

		if ( pTmpNode->pNextNode == NULL) {

			pNewNode->pNextNode = pTmpNode->pNextNode;
			pTmpNode->pNextNode = pNewNode;

			break;
		}

		pTmpNode = pTmpNode->pNextNode;
	}

	return 0;
}


bool getData(singleLinkedList* pHead, char* bufString, int key)
{
	bool bRet = false;

	if ( pHead == NULL) {
		return bRet;
	}

	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return bRet;
	}

	singleLinkedList* pTmpNode = pHead;
	while( pTmpNode ) {

		if( pTmpNode->key == key ) {
			bRet = true;
			strcpy(bufString, pTmpNode->data);
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}

	return bRet;
}

singleLinkedList* popData(singleLinkedList* pHead, int key)
{
	if ( pHead == NULL ) {
		return NULL;
	}

	if ( pHead->pNextNode == NULL) {
		printf("No Data\n");
		return NULL;
	}

	singleLinkedList* pDeletedNode = NULL;
	singleLinkedList* pTmpNode = pHead;
	while( pTmpNode->pNextNode ) {

		if( pTmpNode->pNextNode->key == key ) {
			pDeletedNode= pTmpNode->pNextNode;
			pTmpNode->pNextNode = pTmpNode->pNextNode->pNextNode;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}
	return pDeletedNode;;
}

void showAllData(singleLinkedList* pHead)
{
	if ( pHead == NULL ) {
		return;
	}

	printf("\n");

	singleLinkedList* pTmpNode = pHead->pNextNode;	

	while( pTmpNode ) {
		printf("Node Key[%d] :  Data[%s]\n", pTmpNode->key, pTmpNode->data);
		singleLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


