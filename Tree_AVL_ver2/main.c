#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_avl.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode*);
extern int traverseTree_LevelOrder(treeNode*);

int main()
{
	printf("Treee AVL Test\n");

	treeNode* pRoot = buildBinaryTree();

	traverseTree_LevelOrder(pRoot);

	releaseBinaryTree(pRoot);

	return 0;
}
