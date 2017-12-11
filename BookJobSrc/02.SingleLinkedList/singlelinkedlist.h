#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct NODEDATA {
	int key;
	char data[20]; 
} nodeData;

typedef struct SINGLE_LINKED_LIST {
	nodeData* pData;
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;
*/

typedef struct SINGLE_LINKED_LIST {
	int key;
	char data[20]; 
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;

#endif
