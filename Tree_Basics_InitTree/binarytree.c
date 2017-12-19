#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"


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

	printf("Parent Node[%s]:Key[%d]\n", pParentNode->data, pParentNode->key);

	treeNode* pTreeNode = NULL;

	pTreeNode = createTreeNode(Key, pData);
	if ( pTreeNode == NULL ) {
		printf("Key[%d]:Data[%s] Node Creation FAIL\n", Key, pData);
		return NULL;
	}

	if ( pParentNode->pLeChild == NULL ) {
		printf("Left Child Node[%s]:Key[%d]\n\n", pTreeNode->data, pTreeNode->key);
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

	printf("Parent Node[%s]:Key[%d]\n", pParentNode->data, pParentNode->key);

	treeNode* pTreeNode = NULL;

	pTreeNode = createTreeNode(Key, pData);
	if ( pTreeNode == NULL ) {
		printf("Key[%d]:Data[%s] Node Creation FAIL\n", Key, pData);
		return NULL;
	}

	if ( pParentNode->pRiChild == NULL ) {
		printf("Right Child Node[%s]:Key[%d]\n\n", pTreeNode->data, pTreeNode->key);
		pParentNode->pRiChild = pTreeNode;
	}
	else {
		printf("Right Child Already Inserted =>Key[%d]:Data[%s] \n", Key, pData);
	}
	return pTreeNode;
}

treeNode* buildBinaryTree()
{
	treeNode* pRoot = initTree(0, "Root");

	if ( pRoot == NULL ) {
		printf("Tree Root Init FAIL\n");
		return NULL;
	}

	treeNode* pLeft  = NULL;
    treeNode* pRight = NULL;

    pLeft  = addLeftChild(pRoot, 11, "Root-Left");

    if ( pLeft ) {
		pRight = addRightChild(pLeft, 112, "Root-Left-Right");

	    if ( pRight ) {

			addLeftChild(pRight, 1121, "Root-Left-Right-Left");
		    addRightChild(pRight, 1122, "Root-Left-Right-Right");
	    }

	    pLeft  = addLeftChild(pLeft, 111, "Root-Left-Left");

	    if ( pLeft ) {
	        pRight = addRightChild(pLeft,1112, "Root-Left-Left-Right");
	        pLeft  = addLeftChild(pLeft, 1111, "Root-Left-Left-Left");
        }

    }

	pRight = addRightChild(pRoot, 12, "Root-Right");
	if ( pRight ) {
		pLeft  = addLeftChild(pRight, 121, "Root-Right-Left");
		if( pLeft ) {
			addRightChild(pLeft, 1212, "Root-Right-Left-Right");
		    addLeftChild(pLeft, 1211, "Root-Right-Left-Left");
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

