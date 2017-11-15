#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/tree_postorder.h"

extern void initializeTree();
extern void makeTree();
extern int traverseTree_PostOrder();
extern void showNodeData(treeNode*);

int main()
{
	initializeTree();
	makeTree();
	traverseTree_PostOrder();
	return 0;
}
