#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_postorder.h"

typedef struct STACK_NODE {
	treeNode* pTreeNode;
	struct STACK_NODE* pNextNode;
} stackNode;

