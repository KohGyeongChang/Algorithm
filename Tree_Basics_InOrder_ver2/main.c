#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree_inorder.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_InOrder(treeNode*);

int main()
{
	treeNode* pRoot = buildBinaryTree();

	traverseTree_InOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
