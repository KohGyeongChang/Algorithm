#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	int key;
	char data[20]; 
} nodeData;

typedef struct CIRCULAR_LINKED_LIST {
	nodeData* pData;
	struct CIRCULAR_LINKED_LIST* pNextNode;
} circularLinkedList;

