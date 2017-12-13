#ifndef CIRCULAR_LINKED_LIST_H_VER2
#define CIRCULAR_LINKED_LIST_H_VER2

typedef struct CIRCULAR_LINKED_LIST {
	int key;
	char data[20]; 
	struct CIRCULAR_LINKED_LIST* pNextNode;
} circularLinkedList;

#endif
