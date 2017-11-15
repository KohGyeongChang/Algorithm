#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/tree_inorder.h"

extern void initializeTree();
extern void makeTree();
extern int traverseTree_InOrder();
extern void showNodeData(treeNode*);

int main()
{
	initializeTree();
	makeTree();
	traverseTree_InOrder();
	return 0;
}
