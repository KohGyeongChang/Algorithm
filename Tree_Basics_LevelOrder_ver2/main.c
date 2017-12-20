#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree_levelorder.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_LevelOrder(treeNode*);

int main()
{
	treeNode* pRoot = buildBinaryTree();

	traverseTree_LevelOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
