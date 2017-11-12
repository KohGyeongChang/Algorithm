#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	char data[20]; 
} nodeData;

typedef struct STACK_NODE {
	nodeData* pData;
	struct STACK_NODE* pNextNode;
} stackNode;

