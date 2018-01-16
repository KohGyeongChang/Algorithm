#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree_postorder.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_PostOrder(treeNode*);

int main()
{
	treeNode* pRoot = buildBinaryTree();

	traverseTree_PostOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
