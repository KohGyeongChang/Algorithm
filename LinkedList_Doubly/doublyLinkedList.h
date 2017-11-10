#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODEDATA {
	int key;
	char data[20]; 
} nodeData;

typedef struct DOUBLY_LINKED_LIST {
	nodeData* pData;
	struct DOUBLY_LINKED_LIST* pNextNode;
	struct DOUBLY_LINKED_LIST* pPrevNode;
} doublyLinkedList;

