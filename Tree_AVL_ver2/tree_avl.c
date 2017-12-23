#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree_avl.h"
#include "queue.h"

extern bool initializeQueue(queueNode**, queueNode**);
extern void releaseQueue(queueNode*);
extern bool enQueue(queueNode*, treeNode*);	
extern treeNode* deQueue(queueNode*, queueNode*);
extern void showAllData(queueNode*);
extern bool hasQueueData(queueNode*, queueNode*);

treeNode* createTreeNode( int Key, char* pData)
{
	treeNode* pTreeNode = NULL;

	pTreeNode = (treeNode*)calloc( 1, sizeof(treeNode) );
	if ( pTreeNode ) {
		pTreeNode->key = Key;
		strcpy(pTreeNode->data, pData );
		pTreeNode->pLeChild = NULL;
		pTreeNode->pRiChild = NULL;
	}

	return pTreeNode;
}

treeNode* initTree(int Key, char* pData)
{
	treeNode* pRoot = createTreeNode(Key, pData);
	return pRoot;
}

treeNode* addLeftChild(treeNode* pParentNode, int Key, char* pData )
{
	if ( pParentNode == NULL) {
		printf("Parent Node NULL\n");
		return NULL;
	}

	//printf("Parent Node[%s]:Key[%d]\n", pParentNode->data, pParentNode->key);

	treeNode* pTreeNode = NULL;

	pTreeNode = createTreeNode(Key, pData);
	if ( pTreeNode == NULL ) {
		printf("Key[%d]:Data[%s] Node Creation FAIL\n", Key, pData);
		return NULL;
	}

	if ( pParentNode->pLeChild == NULL ) {
	//	printf("Left Child Node[%s]:Key[%d]\n\n", pTreeNode->data, pTreeNode->key);
		pParentNode->pLeChild = pTreeNode;
	}
	else {
		printf("Left Child Already Inserted =>Key[%d]:Data[%s] \n", Key, pData);
	}
	return pTreeNode;
}


treeNode* addRightChild(treeNode* pParentNode, int Key, char* pData )
{
	if ( pParentNode == NULL) {
		printf("Parent Node NULL\n");
		return NULL;
	}

	//printf("Parent Node[%s]:Key[%d]\n", pParentNode->data, pParentNode->key);

	treeNode* pTreeNode = NULL;

	pTreeNode = createTreeNode(Key, pData);
	if ( pTreeNode == NULL ) {
		printf("Key[%d]:Data[%s] Node Creation FAIL\n", Key, pData);
		return NULL;
	}

	if ( pParentNode->pRiChild == NULL ) {
	//	printf("Right Child Node[%s]:Key[%d]\n\n", pTreeNode->data, pTreeNode->key);
		pParentNode->pRiChild = pTreeNode;
	}
	else {
		printf("Right Child Already Inserted =>Key[%d]:Data[%s] \n", Key, pData);
	}
	return pTreeNode;
}

treeNode* buildBinaryTree()
{
	treeNode* pRoot = initTree(0, "A");

	if ( pRoot == NULL ) {
		printf("Tree Root Init FAIL\n");
		return NULL;
	}

	treeNode* pLeft  = NULL;
    treeNode* pRight = NULL;

    pLeft  = addLeftChild(pRoot, 11, "B");

    if ( pLeft ) {
		pRight = addRightChild(pLeft, 112, "E");

	    if ( pRight ) {

			addLeftChild(pRight, 1121, "I");
		    addRightChild(pRight, 1122, "J");
	    }

	    pLeft  = addLeftChild(pLeft, 111, "D");

	    if ( pLeft ) {
	        pRight = addRightChild(pLeft,1112, "H");
	        pLeft  = addLeftChild(pLeft, 1111, "G");
        }

    }

	pRight = addRightChild(pRoot, 12, "C");
	if ( pRight ) {
		pLeft  = addLeftChild(pRight, 121, "F");
		if( pLeft ) {
			addRightChild(pLeft, 1212, "L");
		    addLeftChild(pLeft, 1211, "K");
		}
	}

	return pRoot;
}

void releaseBinaryTree(treeNode* pTreeNode)
{
	if ( pTreeNode == NULL ) {
		return;
	}

	releaseBinaryTree(pTreeNode->pLeChild);
	releaseBinaryTree(pTreeNode->pRiChild);

	free(pTreeNode);

}


void traverseTree_LevelOrder(treeNode* pTreeNode)
{
	queueNode* pHead = NULL;
	queueNode* pTail = NULL;

	initializeQueue(&pHead, &pTail);
	enQueue(pTail, pTreeNode);

	while ( 1 ) {
		if ( hasQueueData( pHead, pTail) ) {
			pTreeNode = deQueue(pHead, pTail);
			printf("[%s] -> ", pTreeNode->data);

			if ( pTreeNode->pLeChild != NULL) {
				enQueue(pTail, pTreeNode->pLeChild);
			}

			if ( pTreeNode->pRiChild != NULL) {
				enQueue(pTail, pTreeNode->pRiChild);
			}
		}
		else {
			break;
		}

	}

   printf("\n\n");
   releaseQueue(pHead);
}

