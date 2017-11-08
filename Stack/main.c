#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	char data[20]; 
} nodeData;

typedef struct SINGLE_LINKED_LIST {
	nodeData* pData;
	struct singleLinkedList* pNextNode;
} singleLinkedList;

nodeData* createNodeData()
{
	// Caller Checks if pointer is NULL
	nodeData* pData= (nodeData*)calloc(1, sizeof(nodeData));
	return pData;
}


singleLinkedList* createNode(char* data)
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

	return pNewNode;
}

singleLinkedList* createHead()
{
	// Caller Checks if pointer is NULL
	singleLinkedList* pHead = createNode("HEAD");
	return pHead;
}


singleLinkedList* createTail()
{
	// Caller Checks if pointer is NULL
	singleLinkedList* pTail= createNode("TAIL");
	return pTail;
}

singleLinkedList* g_pHead; 
singleLinkedList* g_pTail;

int initializeStack()
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

void releaseStack()
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

int pushData(char* data)
{
	singleLinkedList* pNewNode= createNode(data);
	if ( pNewNode == NULL ) {
		printf("Creaete New NODE FAIL\n");
		return -1;
	}

	pNewNode->pNextNode = g_pHead->pNextNode;
	g_pHead->pNextNode = pNewNode;

	return 0;

}

int popData(char* popedString)
{
	if ( g_pHead->pNextNode == g_pTail ) {
		printf("No Data\n");
		return -1;
	}

	singleLinkedList* pPopedNode = g_pHead->pNextNode; 
	g_pHead->pNextNode = pPopedNode->pNextNode;

	strcpy(popedString, pPopedNode->pData->data);
	releaseNode(pPopedNode);

	return 0;
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
	printf("Stack Test\n");
	initializeStack();
	pushData("Start");
	pushData("Zero");
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
	releaseStack();

	return 0;
}
