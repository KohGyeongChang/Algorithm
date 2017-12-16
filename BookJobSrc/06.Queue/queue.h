#ifndef QUEUE_H_VER2
#define QUEUE_H_VER2

typedef struct QUEUE_NODE{
	int key;
	char data[20]; 
	struct QUEUE_NODE* pPrevNode;
	struct QUEUE_NODE* pNextNode;
} queueNode;

#endif
