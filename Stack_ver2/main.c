#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

extern stackNode* initializeStack();
extern void releaseStack(stackNode*);
extern bool pushData(stackNode*, int key, char* data);
extern stackNode* popData(stackNode* );
extern void showAllData(stackNode*);

int main()
{
	printf("Stack Test\n");

	stackNode* pStack = initializeStack();
	pushData(pStack, 111, "Start");
	showAllData(pStack);

	pushData(pStack, 222, "Zero");
	showAllData(pStack);

	pushData(pStack, 333, "Real");
	showAllData(pStack);

	stackNode* popedNode = NULL;

	popedNode = popData(pStack);
	if( popedNode ) { 
		printf("Poped Node => Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}
	showAllData(pStack);

	popedNode = popData(pStack);
	if( popedNode ) { 
		printf("Poped Node => Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}
	showAllData(pStack);

	popedNode = popData(pStack);
	if( popedNode ) { 
		printf("Poped Node => Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}
	showAllData(pStack);

	popedNode = popData(pStack);
	if( popedNode ) { 
		printf("Poped Node => Key[%d]:Data[%s]\n", popedNode->key, popedNode->data);
	}
	showAllData(pStack);

	showAllData(pStack);
	releaseStack(pStack);

	return 0;
}
