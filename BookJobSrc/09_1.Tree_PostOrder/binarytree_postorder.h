#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct TREE_NODE {

	int key;
	char data[20];
	struct TREE_NODE* pLeChild;
	struct TREE_NODE* pRiChild;

} treeNode;

#endif
