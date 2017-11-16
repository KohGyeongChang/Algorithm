#include "../../Tree_CommLib/Queue/queue.h"

extern bool initializeQueue();
extern void releaseQueue();
extern bool queueHasData();
extern bool pushData(treeNode* data);
extern treeNode* popData();
extern void showAllData();

treeNode* g_pTreeHead;
treeNode* g_pTreeTail;
treeNode* g_pParent;
treeNode* g_pLeftChild;
treeNode* g_pRightChild;

void initializeTree()
{
	g_pTreeHead = (treeNode*)calloc(1, sizeof(treeNode));	
	if ( g_pTreeHead == NULL) {
		printf("Tree Head Memory Allocation FAIL\n");
		return;
	}

	g_pTreeTail = (treeNode*)calloc(1, sizeof(treeNode));	
	if ( g_pTreeTail == NULL) {
		printf("Tree Tail Memory Allocation FAIL\n");
		return;
	}

	g_pTreeHead->left = g_pTreeTail;
	g_pTreeHead->right= g_pTreeTail;

	g_pTreeTail->left = g_pTreeTail;
	g_pTreeTail->right= g_pTreeTail;

	initializeQueue();
}

void releaseTree()
{
	releaseQueue();
}

treeNodeData* createTreeNodeData()
{
	treeNodeData* pData = (treeNodeData*)calloc(1, sizeof(treeNodeData));
	return pData;
}

void makeTree()
{

	///
	///
	g_pParent = (treeNode*)calloc(1, sizeof(treeNode));
	g_pParent->pData = createTreeNodeData();
	g_pParent->pData->data = 'A';

	g_pLeftChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pLeftChild->pData = createTreeNodeData();
	g_pLeftChild->pData->data = 'B';

	g_pRightChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pRightChild->pData = createTreeNodeData();
	g_pRightChild->pData->data = 'C';

	g_pParent->left = g_pLeftChild;
	g_pParent->right= g_pRightChild;

	g_pTreeHead->left = g_pParent;
	g_pTreeHead->right= g_pParent;


	///
	///
	g_pParent = g_pParent->left;

	g_pLeftChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pLeftChild->pData = createTreeNodeData();
	g_pLeftChild->pData->data = 'D';
	g_pLeftChild->left = g_pTreeTail;
	g_pLeftChild->right= g_pTreeTail;

	g_pRightChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pRightChild->pData = createTreeNodeData();
	g_pRightChild->pData->data = 'E';
	g_pRightChild->left = g_pTreeTail;
	g_pRightChild->right= g_pTreeTail;

	g_pParent->left = g_pLeftChild;
	g_pParent->right= g_pRightChild;

	
	///
	///
	g_pParent = g_pTreeHead->right->right;

	g_pLeftChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pLeftChild->pData = createTreeNodeData();
	g_pLeftChild->pData->data = 'F';
	g_pLeftChild->left = g_pTreeTail;
	g_pLeftChild->right= g_pTreeTail;

	g_pRightChild = (treeNode*)calloc(1, sizeof(treeNode));
	g_pRightChild->pData = createTreeNodeData();
	g_pRightChild->pData->data = 'G';
	g_pRightChild->left = g_pTreeTail;
	g_pRightChild->right= g_pTreeTail;

	g_pParent->left = g_pLeftChild;
	g_pParent->right= g_pRightChild;
}


void showNodeData(treeNode *pNode)
{
	printf("[%c] -> ", pNode->pData->data);
}

void traverseTree_LevelOrder()
{
	printf("\nTree LevelOrder Traverse Test\n");
	
	treeNode* pTreeNode = g_pTreeHead->left;
	pushData(pTreeNode);

	while( queueHasData()) {

		pTreeNode = popData();
		showNodeData(pTreeNode);

		if ( pTreeNode->left != g_pTreeTail) {
			pushData(pTreeNode->left);
		}

		if ( pTreeNode->right != g_pTreeTail) {
			pushData(pTreeNode->right);
		}
	}

	printf("\n\n");
}


