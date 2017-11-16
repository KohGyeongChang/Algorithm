#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tree_node.h"

typedef struct STACK_NODE {
	treeNode* pTreeNode;
	struct STACK_NODE* pNextNode;
} stackNode;


#endif
