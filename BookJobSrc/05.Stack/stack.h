#ifndef STACK_H_VER2
#define STACK_H_VER2

typedef struct STACK_NODE {
	int key;
	char data[20]; 
	struct STACK_NODE* pNextNode;
} stackNode;

#endif
