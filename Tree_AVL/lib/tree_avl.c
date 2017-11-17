#include "../../Tree_CommLib/Queue/queue.h"

extern bool initializeQueue();
extern void releaseQueue();
extern bool queueHasData();
extern bool pushData(treeNode* data);
extern treeNode* popData();
extern void showAllData();

treeNode* g_pTreeHead;
treeNode* g_pParent;
treeNode* g_pGrand;
treeNode* g_pChild;
treeNode* g_pBig;

void initializeTree()
{
	g_pTreeHead = (treeNode*)calloc(1, sizeof(treeNode));	
	if ( g_pTreeHead == NULL) {
		printf("Tree Head Memory Allocation FAIL\n");
		return;
	}

	g_pTreeHead->left = g_pTreeHead;
	g_pTreeHead->right= g_pTreeHead;
	g_pBig	= g_pTreeHead;
	
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

bool needBalance() 
{
	bool bRet = false;
	treeNode* pTreeNode;
	pTreeNode = g_pTreeHead->right;

	initializeQueue();

	pushData(pTreeNode);

	while ( queueHasData() ) {

		pTreeNode = popData();

		if ( pTreeNode->balance > 1 || pTreeNode->balance < -1 ) {
			bRet = true;
			break;
		}

		if ( pTreeNode->left != g_pTreeHead ) {
			pushData(pTreeNode->left);
		}

		if ( pTreeNode->right != g_pTreeHead ) {
			pushData(pTreeNode->right);
		}
	}

	releaseQueue();

	return bRet;
}

void AVR_RR() 
{
	g_pParent = g_pGrand->right;
	g_pChild = g_pParent->right;

	if ( g_pGrand->balance == -2 ) {
		g_pBig->right = g_pParent;
		g_pParent->left = g_pGrand;
		g_pGrand->left = g_pTreeHead;
		g_pGrand->right = g_pTreeHead;
	}

	g_pBig->balance++;
	g_pParent->balance = 0;
	g_pGrand->balance = 0;
	g_pChild->balance = 0;
	
}

treeNode* createNewAVLTreeNode(int data)
{
	treeNode* pTreeNode = (treeNode*)calloc(1, sizeof(treeNode));

	if ( pTreeNode == NULL ) {
		return NULL;
	}

	treeNodeData* pNodeData = createTreeNodeData();
	if ( pNodeData == NULL ) {
		return NULL;
	}

	pTreeNode->pData = pNodeData;
	pTreeNode->pData->nData = data;
	pTreeNode->balance = 0;
	pTreeNode->left = g_pTreeHead;
	pTreeNode->right= g_pTreeHead;

	return pTreeNode;
}

treeNode* findParentNodeOfNewNode(treeNode* pTreeNode)
{
	g_pGrand = g_pTreeHead;	
	g_pParent= g_pTreeHead;
	g_pChild = g_pTreeHead->right;

	treeNode* tmpTreeNode = g_pTreeHead->right;

	while ( tmpTreeNode != g_pTreeHead ) {

		g_pChild	= tmpTreeNode;
		g_pBig 		= g_pGrand;
		g_pGrand 	= g_pParent;
		g_pParent 	= g_pChild;

		if ( g_pChild->pData->nData > pTreeNode->pData->nData ) {
			tmpTreeNode = tmpTreeNode->left;
		}
		else {
			tmpTreeNode = tmpTreeNode->right;
		}
	}

	return g_pParent;
}

void insertTreeNode(int data)
{
	treeNode* pTreeNode = createNewAVLTreeNode(data);

	if ( pTreeNode == NULL ) {
		return;
	}

	// if New Node is the first Node
	if ( g_pTreeHead->right == g_pTreeHead ) {
		g_pTreeHead->left = pTreeNode;
		g_pTreeHead->right= pTreeNode;

		return;
	}

	g_pParent = findParentNodeOfNewNode(pTreeNode);

	g_pChild = pTreeNode;

	if ( g_pParent->pData->nData > g_pChild->pData->nData ) {
		g_pParent->left = g_pChild;
		g_pParent->balance++;

		if ( g_pGrand != g_pTreeHead ) {
			g_pGrand->balance++;
		}
	}
	else {
		g_pParent->right = g_pChild;
		g_pParent->balance--;

		if ( g_pGrand != g_pTreeHead ) {
			g_pGrand->balance--;
		}
	}

	if ( needBalance() ) {
		AVR_RR();
	}
}

void showNodeData(treeNode *pNode)
{
	printf("[%c] -> ", pNode->pData->data);
}

void showNodeData_AVL(treeNode *pNode)
{
	printf("[%d] -> ", pNode->pData->nData);
}

void traverseAVLTree_LevelOrder()
{
	printf("\nAVL Tree Level Traverse Test\n");
	
	initializeQueue();

	treeNode* pTreeNode = g_pTreeHead->right;
	pushData(pTreeNode);

	while( queueHasData()) {

		pTreeNode = popData();
		showNodeData_AVL(pTreeNode);

		if ( pTreeNode->left != g_pTreeHead) {
			pushData(pTreeNode->left);
		}

		if ( pTreeNode->right != g_pTreeHead) {
			pushData(pTreeNode->right);
		}
	}

	releaseQueue();

	printf("\n\n");
}


