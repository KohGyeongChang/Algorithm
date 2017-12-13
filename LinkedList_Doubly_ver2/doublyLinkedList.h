#ifndef DOUBLY_LINKED_LIST_H_VER2
#define DOUBLY_LINKED_LIST_H_VER2

typedef struct DOUBLY_LINKED_LIST {
	int key;
	char data[20]; 
	struct DOUBLY_LINKED_LIST* pNextNode;
	struct DOUBLY_LINKED_LIST* pPrevNode;
} doublyLinkedList;


#endif
