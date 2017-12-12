#ifndef SINGLE_LINKED_LIST_H_VER
#define SINGLE_LINKED_LIST_H_VER


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct SINGLE_LINKED_LIST {
	int key;
	char data[20]; 
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;


#endif
