#ifndef QUEUE_H
#define QUEUE_H

typedef struct QUEUE_NODE {
	char data[20]; 
	struct QUEUE_NODE* pNextNode;
} queueNode;

#endif
