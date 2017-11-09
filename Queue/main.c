#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	char data[20]; 
} nodeData;

typedef struct QUEUE_LINKED_LIST {
	nodeData* pData;
	struct QUEUE_LINKED_LIST* pNextNode;
} queueLinkedList;

nodeData* createNodeData()
{
	// Caller Checks if pointer is NULL
	nodeData* pData= (nodeData*)calloc(1, sizeof(nodeData));
	return pData;
}

queueLinkedList* createNode(char* data)
{
	queueLinkedList* pNewNode = (queueLinkedList*)calloc(1, sizeof(queueLinkedList));
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

	return pNewNode;
}

queueLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	queueLinkedList* pHead = createNode("HEAD");
	return pHead;
}


queueLinkedList* createTail()
{
	// Caller Checks if pointer is NULL
	queueLinkedList* pTail= createNode("TAIL");
	return pTail;
}

queueLinkedList* g_pHead; 
queueLinkedList* g_pTail;

int initializequeue()
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

void releasequeue()
{
	queueLinkedList* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		queueLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		free(pTmpNode);
		pTmpNode = pTmpNextNode;
	}
}

void releaseNode(queueLinkedList* pNode)
{
	if ( pNode == NULL ) {
		return;
	}
	if ( pNode->pData ) {
		free(pNode->pData);
	}

	free(pNode);
}

int pushData(char* data)
{
	queueLinkedList* pNewNode= createNode(data);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	queueLinkedList* pTmpNode = g_pHead;

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

int popData(char* popedString)
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return -1;
	}

	queueLinkedList* pPopedNode = g_pHead->pNextNode; 
	g_pHead->pNextNode = pPopedNode->pNextNode;

	strcpy(popedString, pPopedNode->pData->data);
	releaseNode(pPopedNode);

	return 0;
}

void showAllData()
{
	printf("\n");

	queueLinkedList* pTmpNode = g_pHead;	

	while( pTmpNode ) {
		printf("Node Data : [%s]\n", pTmpNode->pData->data);
		queueLinkedList* pTmpNextNode = NULL;	
		if ( pTmpNode->pNextNode ) {
			pTmpNextNode = pTmpNode->pNextNode;
		}
		pTmpNode = pTmpNextNode;
	}
	printf("\n");
}


int main()
{
	printf("queue Test\n");
	initializequeue();
	showAllData();
	pushData("Start");
	showAllData();
	pushData("Zero");
	showAllData();
	pushData("Real");
	showAllData();

	char popString[40] = { 0 };
	int nRet = -1;
	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}
	showAllData();
	releasequeue();

	return 0;
}
