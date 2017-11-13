#include "tree_preorder.h"
#include "../../Stack/lib/stack.h"

extern nodeData* createNodeData();
extern stackNode* createNode(char* data);
extern stackNode* createHead();
extern stackNode* createTail();
extern stackNode* g_pHead;
extern stackNode* g_pTail;
extern int initializeStack();
extern void releaseStack();
extern void releaseNode(stackNode* pNode);
extern int isStackEmpty();
extern int pushData(char* data);
extern int popData(char* popedString);
extern void showAllData();

