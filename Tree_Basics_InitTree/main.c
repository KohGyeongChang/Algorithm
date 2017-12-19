#include <stdio.h>
#include "binarytree.h"

extern treeNode* buildBinaryTree();
extern void releaseBinaryTree(treeNode* );

int main()
{
	treeNode* pRoot = buildBinaryTree();

	releaseBinaryTree(pRoot);

	return 0;
}
