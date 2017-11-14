#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/tree_preorder.h"

extern void initializeTree();
extern void makeTree();
extern int traverseTree_PreOrder();
extern void showNodeData(treeNode*);

int main()
{
	initializeTree();
	makeTree();
	traverseTree_PreOrder();
	return 0;
}
