#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublyLinkedList.h"

nodeData* createNodeData()
{
	// Caller Checks if pointer is NULL
	nodeData* pData= (nodeData*)calloc(1, sizeof(nodeData));
	return pData;
}

doublyLinkedList* createNode(char* data, int key)
{
	doublyLinkedList* pNewNode = (doublyLinkedList*)calloc(1, sizeof(doublyLinkedList));
	if ( pNewNode == NULL ) {
		printf("New Node HEAD Memory Allocation FAIL\n");
		return NULL;
	}

	nodeData* pData = createNodeData();
	if ( pData== NULL ) {
		printf("NOde DATA Memory Allocation FAIL\n");
		return NULL;
	}

	pNewNode->pData = pData;
	memcpy(pNewNode->pData->data, data, strlen(data) );

	pNewNode->pData->key = key;

	return pNewNode;
}

doublyLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	doublyLinkedList* pHead = createNode("HEAD", 1);
	return pHead;
}


doublyLinkedList* createTail()
{
	// Caller Checks if pointer is NULL
	doublyLinkedList* pTail= createNode("TAIL", 100);
	return pTail;
}

doublyLinkedList* g_pHead; 
doublyLinkedList* g_pTail;

int initializedoublyLinkedList()
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
	g_pHead->pPrevNode = NULL;
	g_pTail->pNextNode = NULL;
	g_pTail->pPrevNode = g_pHead;

	return 0;
}

void releasedoublyLinkedList()
{
	doublyLinkedList* pTmpNode = g_pHead;	

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
	if ( pNode->pData ) {
		free(pNode->pData);
	}

	free(pNode);
}

int addData(char* data, int key)
{
	doublyLinkedList* pNewNode= createNode(data, key);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	doublyLinkedList* pTmpNode = g_pHead;
	while( 1 ) {

		if ( pTmpNode->pNextNode == g_pTail) {

			pNewNode->pNextNode = pTmpNode->pNextNode;
			pNewNode->pPrevNode = pTmpNode->pNextNode->pPrevNode;

			pTmpNode->pNextNode->pPrevNode = pNewNode;
			pTmpNode->pNextNode = pNewNode;

			break;
		}

		pTmpNode = pTmpNode->pNextNode;
	}

	return 0;
}

int getData(char* bufString, int key)
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return -1;
	}

	int nFoundFlag = -1;
	doublyLinkedList* pTmpNode = g_pHead;
	while( pTmpNode ) {

		if( pTmpNode->pData->key == key ) {
			nFoundFlag = 0;
			break;
		}

		pTmpNode = pTmpNode->pNextNode;
	}

	if ( nFoundFlag == 0 ) {
		strcpy(bufString, pTmpNode->pData->data);
	}

	return nFoundFlag;
}

int deleteData(int key)
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return -1;
	}

	int nFoundFlag = -1;
	doublyLinkedList* pTmpNode = g_pHead;
	while( pTmpNode->pNextNode ) {

		if( pTmpNode->pNextNode->pData->key == key ) {
			nFoundFlag = 0;
			break;
		}

		pTmpNode = pTmpNode->pNextNode;
	}

	if ( nFoundFlag == 0 ) {
		doublyLinkedList* pDeletedNode= pTmpNode->pNextNode;
		pDeletedNode->pNextNode->pPrevNode = pDeletedNode->pPrevNode;
		pTmpNode->pNextNode = pDeletedNode->pNextNode;
		releaseNode(pDeletedNode);
	}

	return nFoundFlag;
}

void showAllData()
{
	printf("Show Data\n");

	doublyLinkedList* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->pData->data);
		doublyLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}

void showAllData_R()
{
	printf("Reversly Show Data\n");

	doublyLinkedList* pTmpNode = g_pTail;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->pData->data);
		doublyLinkedList* pTmpPrevNode = NULL;	
		if ( pTmpNode->pPrevNode ) {
			pTmpPrevNode = pTmpNode->pPrevNode;
		}
		pTmpNode = pTmpPrevNode;
	}
	printf("\n");
}

