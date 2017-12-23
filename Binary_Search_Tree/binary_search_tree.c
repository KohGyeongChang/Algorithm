#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"
#include "stack.h"

extern treeNode* pushData(stackNode*, treeNode*);
extern bool hasStackData(stackNode*);
extern treeNode* popData(stackNode*);
extern void showData(stackNode*);
extern stackNode* initializeStack();
extern void releaseStack(stackNode*);

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
	treeNode* pRoot = initTree(100, "A");

	if ( pRoot == NULL ) {
		printf("Tree Root Init FAIL\n");
		return NULL;
	}

	treeNode* pLeft  = NULL;
    treeNode* pRight = NULL;

    pLeft  = addLeftChild(pRoot, 80, "B");

    if ( pLeft ) {
		pRight = addRightChild(pLeft, 90, "E");

	    if ( pRight ) {

			addLeftChild(pRight, 85, "I");
		    addRightChild(pRight, 95, "J");
	    }

	    pLeft  = addLeftChild(pLeft, 60, "D");

	    if ( pLeft ) {
	        pRight = addRightChild(pLeft, 70, "H");
	        pLeft  = addLeftChild(pLeft, 50, "G");
        }

    }

	pRight = addRightChild(pRoot, 120, "C");
	if ( pRight ) {
		pLeft  = addLeftChild(pRight, 110, "F");
		if( pLeft ) {
			addRightChild(pLeft, 115, "L");
		    addLeftChild(pLeft, 105, "K");
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


void traverseTree_InOrder(treeNode* ptreeNode)
{
	printf("\nTree InOrder Traverse Test\n");
	stackNode* pStack  = initializeStack();

	treeNode* pTreeNode = ptreeNode;
	while ( 1 ) {

		while ( pTreeNode ) {
			pushData(pStack, pTreeNode);
			pTreeNode = pTreeNode->pLeChild;
		}

		if ( hasStackData(pStack) ) {
			pTreeNode = popData(pStack);
			//printf("[%s] -> ", pTreeNode->data);
			printf("[%d] -> ", pTreeNode->key);
			pTreeNode = pTreeNode->pRiChild;
		}
		else {
			break;
		}

	}

   printf("\n\n");
   releaseStack(pStack);
}

treeNode* search(treeNode* pTreeNode, int key)
{
	if ( pTreeNode == NULL ) {
		return NULL;
	}

	treeNode* pFoundNode 	= pTreeNode;

	while ( pFoundNode ) {
		if ( pFoundNode->key == key ) {
			break;
		}
		else if ( pFoundNode->key < key ) {
			pFoundNode = pFoundNode->pRiChild;
		}
		else if ( pFoundNode->key > key ) {
			pFoundNode = pFoundNode->pLeChild;
		}
	}
	return pFoundNode;
}


treeNode* findParentNode(treeNode* pTreeNode, int Key)
{
	if ( pTreeNode == NULL ) {
		return NULL;
	}

	treeNode* pFoundNode 	= pTreeNode;
	treeNode* pParentNode	= pTreeNode;

	while ( pFoundNode ) {
		if ( pFoundNode->key == Key ) {
			break;
		}
		else if ( pFoundNode->key < Key ) {
			pParentNode = pFoundNode;
			pFoundNode = pFoundNode->pRiChild;
		}
		else if ( pFoundNode->key > Key ) {
			pParentNode = pFoundNode;
			pFoundNode = pFoundNode->pLeChild;
		}
	}
	return pParentNode;
}

void insert(treeNode* pTreeNode, int Key, char* pData)
{
	treeNode* pParentNode = findParentNode(pTreeNode, Key); 

	if ( pParentNode == NULL ) {
		return ;
	}

	treeNode* pNewNode   = createTreeNode( Key, pData);

	if ( pNewNode->key < pParentNode->key ) {
		pParentNode->pLeChild = pNewNode;
	}
	else if ( pNewNode->key > pParentNode->key ) {
		pParentNode->pRiChild = pNewNode;
	}
}

treeNode* findNode(treeNode* pTreeNode, int Key)
{
	if ( pTreeNode == NULL ) {
		return NULL;
	}

	treeNode* pFoundNode	= NULL;
	treeNode* pParentNode	= findParentNode(pTreeNode, Key); 

	if ( pParentNode->pLeChild->key == Key ) {
		pFoundNode = pParentNode->pLeChild;
		printf("findNode() => Parent Key[%d], Found Left Key[%d]\n", pParentNode->key, pFoundNode->key);
	}
	else if ( pParentNode->pRiChild->key == Key ) {
		pFoundNode = pParentNode->pRiChild;
		printf("findNode() => Parent Key[%d], Found Right Key[%d]\n", pParentNode->key, pFoundNode->key);
	}
	else {
		printf("findNode() => Key[%d] NULL\n", Key); 
		pFoundNode = NULL;
	}
	return pFoundNode;
}

int checkNumOfChild(treeNode* pFoundNode, int Key)
{
	if ( pFoundNode == NULL ) {
		return -1;
	}

	if ( pFoundNode->pLeChild == NULL && pFoundNode->pRiChild == NULL ) {
		return 0;
	}
	else if ( pFoundNode->pLeChild != NULL && pFoundNode->pRiChild != NULL ) {
		return 2;
	}
	else {
		return 1;
	}
}

void deleteZero(treeNode* pTreeNode, treeNode* pParentNode, treeNode* pFoundNode)
{
	if ( pParentNode == NULL ) {
		return;
	}

	if ( pParentNode->pLeChild  == pFoundNode ) {
		pParentNode->pLeChild = NULL;
	}
	else if ( pParentNode->pRiChild == pFoundNode ) {
		pParentNode->pRiChild = NULL;
	}
	free( pFoundNode ) ;
}

void deleteOne(treeNode* pTreeNode, treeNode* pParentNode, treeNode* pFoundNode)
{
	if ( pParentNode == NULL ) {
		return;
	}

	if ( pParentNode->pLeChild == pFoundNode ) {
		if ( pFoundNode->pLeChild ) {
			pParentNode->pLeChild = pFoundNode->pLeChild;
		}
		else {
			pParentNode->pLeChild = pFoundNode->pRiChild;
		}
	}
	else {
		if ( pFoundNode->pLeChild ) {
			pParentNode->pRiChild = pFoundNode->pLeChild;
		}
		else {
			pParentNode->pRiChild = pFoundNode->pRiChild;
		}
	}
	free( pFoundNode ) ;
}

void deleteTwo(treeNode* pTreeNode, treeNode* pParentNode, treeNode* pFoundNode)
{
	if ( pFoundNode == NULL ) {
		return;
	}
	treeNode* pBridge = pFoundNode->pLeChild;
	treeNode* pTmp = pBridge->pRiChild;
	treeNode* pReplaceNode = NULL;

	while ( pTmp ) {
		pReplaceNode = pTmp;
		pTmp = pTmp->pRiChild;
	}
	pBridge->pRiChild = pReplaceNode->pLeChild;
	pReplaceNode->pLeChild = pFoundNode->pLeChild;
	pReplaceNode->pRiChild = pFoundNode->pRiChild;

	if ( pParentNode->pLeChild == pFoundNode ) {
		pParentNode->pLeChild = pReplaceNode;
	}
	else {
		pParentNode->pRiChild = pReplaceNode;
	}
	free( pFoundNode ) ;
}

void deleteNode(treeNode* pTreeNode, treeNode* pParentNode, treeNode* pFoundNode, int NumOfChild)
{
	switch ( NumOfChild ) {
		case 0:
			deleteZero(pTreeNode, pParentNode, pFoundNode);
			break;
		case 1:
			deleteOne(pTreeNode, pParentNode, pFoundNode);
			break;
		case 2:
			deleteTwo(pTreeNode, pParentNode, pFoundNode);
			break;
		default:
			break;
	}
}

void delete(treeNode* pTreeNode, int Key)
{
	treeNode* pParentNode = findParentNode(pTreeNode, Key); 
	treeNode* pFoundNode = findNode(pTreeNode, Key);
	if ( pFoundNode == NULL ) {
		printf("delete() => Key[%d] NULL\n", Key); 
		return;
	}
	int NumOfChild = checkNumOfChild(pFoundNode, Key); 
	printf("delete() => checkNumOfChild() => Node Found Key[%d]:Data[%s]\n", pFoundNode->key, pFoundNode->data);
	deleteNode(pTreeNode, pParentNode, pFoundNode, NumOfChild);
}



