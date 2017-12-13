#ifndef STACK_H
#define STACK_H

typedef struct STACK_NODE {
	char data[20]; 
	struct STACK_NODE* pNextNode;
} stackNode;

#endif
