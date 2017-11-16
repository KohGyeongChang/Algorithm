#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct TREENODEDATA {
	char data;
	int nData;
}treeNodeData;

typedef struct TREENODE {
	treeNodeData* pData;
	int balance;
	struct TREENODE* left;
	struct TREENODE* right;
} treeNode;


#endif
