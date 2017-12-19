#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree_postorder.h"
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


void traverseTree_PostOrder(treeNode* ptreeNode)
{
	printf("\nTree PostOrder Traverse Test\n");
	stackNode* pStack  = initializeStack();

	treeNode* pTreeNode = ptreeNode;
	treeNode* pAlreadyPut = NULL;
	treeNode* pAlreadyVisited = NULL;

	while ( 1 ) {

		while ( pTreeNode && (pTreeNode != pAlreadyVisited)) {
		
			if ( pTreeNode != pAlreadyPut ) {
				pushData(pStack, pTreeNode);
			}

			if ( pTreeNode->pRiChild ) {
				pushData(pStack, pTreeNode->pRiChild);
			}

			if ( pTreeNode->pLeChild ) {
				pushData(pStack, pTreeNode->pLeChild);
			}
		
			pAlreadyPut = pTreeNode->pLeChild; 
			pTreeNode = pTreeNode->pLeChild;
		}

		if ( hasStackData(pStack) ) {
			pTreeNode = popData(pStack);

			if ( pTreeNode->pLeChild && pTreeNode != pAlreadyVisited) {
				pushData(pStack, pTreeNode);
			}

			if ( pTreeNode->pRiChild == NULL || pTreeNode->pRiChild == pAlreadyVisited ) {
				printf("[%s] -> ", pTreeNode->data);
				pAlreadyVisited = pTreeNode;
			}


		}
		else {
			break;
		}

	}



   printf("\n\n");
   releaseStack(pStack);
}










