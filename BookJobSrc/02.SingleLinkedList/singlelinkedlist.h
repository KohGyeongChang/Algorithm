#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

typedef struct SINGLE_LINKED_LIST {
	int key;
	char data[20]; 
	struct SINGLE_LINKED_LIST* pNextNode;
} singleLinkedList;

#endif
