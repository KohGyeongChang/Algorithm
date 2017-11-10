#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	char data[20]; 
} nodeData;

typedef struct QUEUE_LINKED_LIST {
	nodeData* pData;
	struct QUEUE_LINKED_LIST* pNextNode;
} queueLinkedList;

