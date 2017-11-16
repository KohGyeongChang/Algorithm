#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../tree_node.h"

typedef struct QUEUE_NODE {
	treeNode* pTreeNode;
	struct QUEUE_NODE* pNextNode;
} queueNode;

#endif
