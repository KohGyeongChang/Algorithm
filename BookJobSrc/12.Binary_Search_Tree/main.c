#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_InOrder(treeNode*);
extern treeNode* search(treeNode*, int);
extern void insert(treeNode*, int, char*);
extern void delete(treeNode*, int);

int main()
{
	treeNode* pRoot = buildBinaryTree();

	traverseTree_InOrder(pRoot);

	treeNode* pFoundNode = NULL;

	pFoundNode = search(pRoot, 70);
	if ( pFoundNode ) {
		printf("Found Node Key[%d]:Data[%s]\n", pFoundNode->key, pFoundNode->data);
	}
	else {
		printf("FAIL:Found Node \n");
	}

	pFoundNode = search(pRoot, 107);
	if ( pFoundNode ) {
		printf("Found Node Key[%d]:Data[%s]\n", pFoundNode->key, pFoundNode->data);
	}
	else {
		printf("FAIL:Found Node \n");
	}

	/*
	insert(pRoot, 45,"M");
	traverseTree_InOrder(pRoot);

	insert(pRoot, 65,"N");
	traverseTree_InOrder(pRoot);
	*/

	printf("Trying To Delete '80'\n"); 
	delete(pRoot, 80);
	traverseTree_InOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
