#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/tree_preorder.h"

extern void initializeTree();
extern void makeTree();
extern int traverseTree();
extern void showNodeData(treeNode*);

int main()
{
	printf("Tree PreOrder Test\n");

	initializeTree();
	makeTree();
	traverseTree();
	return 0;
}
