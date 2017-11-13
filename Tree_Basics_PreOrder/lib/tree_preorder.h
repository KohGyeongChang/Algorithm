#ifndef TREE_PREORDER_H
#define TREE_PREORDER_H

typedef struct TREENODEDATA {
	char data[20];
}treeNodeData;

typedef struct TREENODE {
	treeNodeData* pData;
	struct TREENODE* left;
	struct TREENODE* right;
} treeNode;


#endif
