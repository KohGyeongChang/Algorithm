#ifndef TREE_PREORDER_H
#define TREE_PREORDER_H

typedef struct TREENODEDATA {
	int data;
}treeNodeData;

typedef struct TREEAVLNODE {
	treeNodeData* pData;
	int balance; // Only For AVL Tree
	struct TREENODE* left;
	struct TREENODE* right;
} treeAVLNode;


#endif
