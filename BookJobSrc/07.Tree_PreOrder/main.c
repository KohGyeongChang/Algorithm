#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree_preorder.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_PreOrder(treeNode*);

int main()
{
	treeNode* pRoot = buildBinaryTree();

	traverseTree_PreOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
