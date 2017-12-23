#ifndef QUEUE_H_VER2
#define QUEUE_H_VER2

#include "tree_avl.h"

typedef struct QUEUE_NODE{
	treeNode* pTreeNode;
	struct QUEUE_NODE* pPrevNode;
	struct QUEUE_NODE* pNextNode;
} queueNode;

#endif
