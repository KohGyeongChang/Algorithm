#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void initializeTree();
extern void insertTreeNode();
extern int traverseAVLTree_LevelOrder();

int main()
{
	initializeTree();

	insertTreeNode(10);
	traverseAVLTree_LevelOrder();

	insertTreeNode(15);
	traverseAVLTree_LevelOrder();

	insertTreeNode(20);
	traverseAVLTree_LevelOrder();

	insertTreeNode(25);
	traverseAVLTree_LevelOrder();

	insertTreeNode(30);
	traverseAVLTree_LevelOrder();

	insertTreeNode(35);
	traverseAVLTree_LevelOrder();

	insertTreeNode(40);
	traverseAVLTree_LevelOrder();

	insertTreeNode(45);
	traverseAVLTree_LevelOrder();

	insertTreeNode(50);
	traverseAVLTree_LevelOrder();

	insertTreeNode(55);
	traverseAVLTree_LevelOrder();

	insertTreeNode(60);
	traverseAVLTree_LevelOrder();

	insertTreeNode(65);
	traverseAVLTree_LevelOrder();

	return 0;
}
