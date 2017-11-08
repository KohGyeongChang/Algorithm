#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	int key;
	char data[20]; 
} nodeData;

typedef struct SINGLE_LINKED_LIST {
	nodeData* pData;
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;

nodeData* createNodeData()
{
	// Caller Checks if pointer is NULL
	nodeData* pData= (nodeData*)calloc(1, sizeof(nodeData));
	return pData;
}

singleLinkedList* createNode(char* data, int key)
{
	singleLinkedList* pNewNode = (singleLinkedList*)calloc(1, sizeof(singleLinkedList));
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

singleLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	singleLinkedList* pHead = createNode("HEAD", 1);
	return pHead;
}


singleLinkedList* createTail()
{
	// Caller Checks if pointer is NULL
	singleLinkedList* pTail= createNode("TAIL", 100);
	return pTail;
}

singleLinkedList* g_pHead; 
singleLinkedList* g_pTail;

int initializeSingleLinkedList()
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

void releaseSingleLinkedList()
{
	singleLinkedList* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		singleLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(singleLinkedList* pNode)
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
	singleLinkedList* pNewNode= createNode(data, key);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	singleLinkedList* pTmpNode = g_pHead;
	while( 1 ) {

		if ( pTmpNode->pNextNode == g_pTail) {

			pNewNode->pNextNode = pTmpNode->pNextNode;
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
	singleLinkedList* pTmpNode = g_pHead;
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
	singleLinkedList* pTmpNode = g_pHead;
	while( pTmpNode->pNextNode ) {

		if( pTmpNode->pNextNode->pData->key == key ) {
			nFoundFlag = 0;
			break;
		}

		pTmpNode = pTmpNode->pNextNode;
	}

	if ( nFoundFlag == 0 ) {
		singleLinkedList* pDeletedNode= pTmpNode->pNextNode;
		pTmpNode->pNextNode = pTmpNode->pNextNode->pNextNode;
		releaseNode(pDeletedNode);
	}

	return nFoundFlag;
}

void showAllData()
{
	printf("\n");

	singleLinkedList* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->pData->data);
		singleLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


int main()
{
	printf("Single Linked List Test\n");
	initializeSingleLinkedList();
	addData("Start", 2);
	addData("Zero", 22);
	addData("Real", 222);
	showAllData();

	char bufString[40] = { 0 };
	int nRet = -1;
	nRet = getData(bufString, 2);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 22);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 222);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 234);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	deleteData(222);
	showAllData();
	releaseSingleLinkedList();

	return 0;
}
