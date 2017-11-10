#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	int key;
	char data[20]; 
} nodeData;

typedef struct SINGLE_LINKED_LIST {
	nodeData* pData;
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;

