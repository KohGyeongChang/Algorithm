#ifndef STACK_H_VER2
#define STACK_H_VER2

#include "binarytree_postorder.h"

typedef struct STACK_NODE {
	treeNode* pTreeNode;
	struct STACK_NODE* pNextNode;
} stackNode;

#endif
